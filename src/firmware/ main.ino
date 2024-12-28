#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include <HardwareSerial.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <PubSubClient.h>

// Constantes de configuração MQTT e WiFi
const char* MQTT_SERVER = "848c6529c87c4961b45a47c5680c369e.s1.eu.hivemq.cloud";
const int MQTT_PORT = 8883;
const char* MQTT_USER = "exodia";
const char* MQTT_PASS = "Exodia#123";
const char* WIFI_SSID = "SHARE-RESIDENTE";
const char* WIFI_PASSWORD = "Share@Residente23";

// Configuração dos clientes WiFi e MQTT com suporte a TLS
WiFiClientSecure secureClient;
PubSubClient mqttClient(secureClient);

// Classe para controle do display LCD: Gerencia a exibição de mensagens no display, permitindo inicialização e mostrar textos
class LCDDisplay {
private:
    LiquidCrystal_I2C lcd;
public:
    // Construtor que configura o endereço e dimensões do display
    LCDDisplay(uint8_t address, uint8_t cols, uint8_t rows) : lcd(address, cols, rows) {}
    
    // Inicializa o display LCD com backlight
    void init() {
        lcd.init();
        lcd.backlight();
    }
    
    // Exibe uma mensagem no display LCD e também no monitor serial
    void showMessage(const char* message) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(message);
        Serial.println(message);
    }
};

// Classe de conexão MQTT: Gerencia conexão, reconexão e envio de mensagens
class MQTTConnection {
private:
    LCDDisplay& display;
    WiFiClientSecure& client;
    PubSubClient& mqttClient;

public:
    // Construtor que inicializa conexão MQTT com referências a objetos externos
    MQTTConnection(LCDDisplay& disp, WiFiClientSecure& secClient, PubSubClient& mqttCli) 
        : display(disp), client(secClient), mqttClient(mqttCli) {}

    // Inicializa configurações de segurança e conexão MQTT
    void setup() {
        client.setInsecure(); // Desativa verificação de certificado (para testes)
        mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
        mqttClient.setCallback([this](char* topic, byte* payload, unsigned int length) {
            this->callback(topic, payload, length);
        });
    }

    // Tenta reconectar ao broker MQTT
    void reconnect() {
        while (!mqttClient.connected()) {
            display.showMessage("Conectando MQTT...");
            
            if (mqttClient.connect("ESP32AccessControl", MQTT_USER, MQTT_PASS)) {
                display.showMessage("MQTT Conectado!");
                
                // Subscreve em tópicos relevantes
                mqttClient.subscribe("exodia/comando");
                mqttClient.subscribe("exodia/configuracao");
            } else {
                display.showMessage("Falha MQTT");
                delay(5000);
            }
        }
    }

    // Envia mensagem para um tópico MQTT
    void sendMessage(const char* topic, const char* message) {
        if (mqttClient.publish(topic, message)) {
            display.showMessage("Msg Enviada!");
        } else {
            display.showMessage("Erro no envio");
        }
    }

private:
    // Callback para processar mensagens recebidas
    void callback(char* topic, byte* payload, unsigned int length) {
        // Converte payload para string
        String message;
        for (unsigned int i = 0; i < length; i++) {
            message += (char)payload[i];
        }

        // Processa mensagens com base no tópico
        if (String(topic) == "exodia/comando") {
            if (message == "CADASTRO_ON") {
                // Lógica para habilitar modo de cadastro
                display.showMessage("Modo Cadastro");
            } else if (message == "CADASTRO_OFF") {
                // Lógica para desabilitar modo de cadastro
                display.showMessage("Modo Normal");
            }
        }
    }
};

// Classe para conexão WiFi: Gerencia a conexão com a rede wireless, incluindo tentativas de conexão e status
class WiFiConnection {
private:
    const char* ssid;
    const char* password;
    LCDDisplay& display;

public:
    // Construtor que configura os parâmetros de conexão WiFi
    WiFiConnection(const char* ssid, const char* password, LCDDisplay& display)
        : ssid(ssid), password(password), display(display) {}

    // Realiza a conexão com a rede WiFi, com limite de tentativas e feedback no display
    void connect() {
        Serial.print("Conectando a ");
        Serial.println(ssid);
        display.showMessage("Conectando ao WiFi...");

        WiFi.begin(ssid, password);
        int attempt = 0;

        while (WiFi.status() != WL_CONNECTED) {
            delay(1000);
            Serial.print(".");
            attempt++;
            if (attempt > 10) {
                display.showMessage("WiFi Falhou!");
                return;
            }
        }
        display.showMessage("WiFi Conectado!");
    }

    // Verifica o status atual da conexão WiFi
    bool isConnected() {
        return WiFi.status() == WL_CONNECTED;
    }
};

// Classe para controle do LED RGB: Permite configurar e alterar as cores do LED
class LedRGB {
private:
    int pinRed, pinGreen, pinBlue;
public:
    // Construtor que define os pinos para cada cor do LED
    LedRGB(int red, int green, int blue) : pinRed(red), pinGreen(green), pinBlue(blue) {}

    // Configura os pinos do LED RGB como saída
    void init() {
        pinMode(pinRed, OUTPUT);
        pinMode(pinGreen, OUTPUT);
        pinMode(pinBlue, OUTPUT);
    }

    // Define a cor do LED RGB ligando ou desligando cada pino
    void setColor(bool red, bool green, bool blue) {
        digitalWrite(pinRed, red ? HIGH : LOW);
        digitalWrite(pinGreen, green ? HIGH : LOW);
        digitalWrite(pinBlue, blue ? HIGH : LOW);
    }
};

// Classe para controle do buzzer: Permite emitir sinais sonoros
class Buzzer {
private:
    int pin;
public:
    // Construtor que define o pino do buzzer
    Buzzer(int pin) : pin(pin) {}

    // Configura o pino do buzzer como saída
    void init() {
        pinMode(pin, OUTPUT);
    }

    // Emite um sinal sonoro com duração configurável
    void beep(int duration = 100) {
        digitalWrite(pin, HIGH);
        delay(duration);
        digitalWrite(pin, LOW);
    }
};

// Classe para controle do sensor biométrico: Gerencia a autenticação por impressão digital
class BiometricSensor {
private:
    Adafruit_Fingerprint finger;
    LCDDisplay& display;
public:
    // Construtor que configura a porta serial e o display para feedback
    BiometricSensor(HardwareSerial* serial, LCDDisplay& display)
        : finger(serial), display(display) {}

    // Inicializa o sensor biométrico e verifica se está funcionando
    void init() {
        finger.begin(57600);
        if (!finger.verifyPassword()) {
            Serial.println("Erro Biometrico");
            while (true);
        }
        Serial.println("Biometrico OK");
    }

    // Realiza a autenticação por impressão digital com múltiplas etapas de verificação
    bool authenticate() {
        display.showMessage("Posicione o dedo...");
        int result;

        while (true) {
            result = finger.getImage();
            if (result == FINGERPRINT_NOFINGER) {
                delay(500);
            } else if (result == FINGERPRINT_OK) {
                break;
            } else {
                display.showMessage("Erro na leitura");
                delay(1000);
                return false;
            }
        }

        result = finger.image2Tz();
        if (result != FINGERPRINT_OK) {
            display.showMessage("Erro ao processar");
            delay(1000);
            return false;
        }

        result = finger.fingerSearch();
        if (result == FINGERPRINT_OK) {
            char buffer[16];
            sprintf(buffer, "ID: %d", finger.fingerID);
            display.showMessage(buffer);
            delay(2000);
            return true;
        } else {
            display.showMessage("Nao encontrado");
            delay(1000);
            return false;
        }
    }
};

// Classe para controle do sensor RFID: Gerencia a leitura de tags RFID
class RFIDSensor {
private:
    MFRC522 rfid;
public:
    // Construtor que define os pinos SDA e RST do módulo RFID
    RFIDSensor(uint8_t sda, uint8_t rst) : rfid(sda, rst) {}

    // Inicializa o protocolo SPI e o módulo RFID
    void init() {
        SPI.begin();
        rfid.PCD_Init();
    }

    // Lê o UID (Identificador único) de uma tag RFID presente
    String readUID() {
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
            return "";
        }
        String uid = "";
        for (byte i = 0; i < rfid.uid.size; i++) {
            uid += String(rfid.uid.uidByte[i], HEX);
        }
        rfid.PICC_HaltA();
        return uid;
    }
};

// Classe principal que integra todos os componentes do sistema de controle de acesso
class AccessSystem {
private:
    LCDDisplay display;
    WiFiConnection wifi;
    MQTTConnection mqtt;
    LedRGB led;
    Buzzer buzzer;
    BiometricSensor biometrics;
    RFIDSensor rfid;

    const int relayPin;
    const int buttonPin;
    bool cadastroMode = false;  // Flag para modo de cadastro

public:
    // Construtor que inicializa todos os componentes com pinos e configurações específicas
    AccessSystem()
        : display(0x27, 16, 2),
          wifi(WIFI_SSID, WIFI_PASSWORD, display),
          mqtt(display, secureClient, mqttClient),
          led(33, 32, 27),
          buzzer(26),
          biometrics(&Serial1, display),
          rfid(21, 22),
          relayPin(25),
          buttonPin(34) {}

    // Método de inicialização que configura todos os módulos do sistema
    void init() {
        Serial.begin(115200);
        pinMode(relayPin, OUTPUT);
        pinMode(buttonPin, INPUT);

        display.init();
        led.init();
        buzzer.init();
        biometrics.init();
        rfid.init();
        
        wifi.connect();
        mqtt.setup();
        
        display.showMessage("Sistema OK");
        delay(2000);
    }

    // Método principal que executa o loop do sistema, verificando conexão WiFi e tentativas de acesso
    void run() {
        // Verifica conexão MQTT
        if (!mqttClient.connected()) {
            mqtt.reconnect();
        }
        mqttClient.loop();

        // Verifica modo de operação
        if (cadastroMode) {
            handleCadastro();
        } else {
            handleAccess();
        }
    }

private:
    // Lógica de cadastro
    void handleCadastro() {
        if (rfid.readUID() != "") {
            mqtt.sendMessage("exodia/cadastro/rfid", "Novo RFID detectado");
        }

        if (biometrics.authenticate()) {
            mqtt.sendMessage("exodia/cadastro/biometria", "Nova biometria detectada");
        }
    }

    // Lógica de acesso
    void handleAccess() {
        String rfidUID = rfid.readUID();
        if (rfidUID != "") {
            mqtt.sendMessage("exodia/acesso/rfid", rfidUID.c_str());
            processAccess("RFID OK");
        }

        if (biometrics.authenticate()) {
            mqtt.sendMessage("exodia/acesso/biometria", "Autenticado");
            processAccess("Biometria OK");
        }
    }

    // Processa acesso concedido
    void processAccess(const char* message) {
        display.showMessage(message);
        led.setColor(false, true, false);
        buzzer.beep();
        digitalWrite(relayPin, HIGH);
        
        // Envia confirmação de acesso
        mqtt.sendMessage("exodia/acesso/status", "LIBERADO");
        
        delay(5000);
        digitalWrite(relayPin, LOW);
        led.setColor(false, false, false);
    }
};

AccessSystem system;

// Funções Arduino padrão
void setup() {
    system.init();
}

void loop() {
    system.run();
}
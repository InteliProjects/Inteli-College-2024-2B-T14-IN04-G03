#include <PubSubClient.h>
#include <WiFi.h>
#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal_I2C.h>

// Definir qual porta serial usar no ESP32
HardwareSerial mySerial(2); // UART2 no ESP32 (GPIO 16 = RX2, GPIO 17 = TX2)

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

uint8_t id;

// Inicializando os objetos das classes das bibliotecas
WiFiClient wifiClient;
PubSubClient client(wifiClient);

// Constante das informações para conexão Wi-Fi
const char* ssid = "guti";
const char* password = "";

// Constantes para conexão com o Broker MQTT
const int mqtt_port = 1883;
const char* mqtt_server = "broker.hivemq.com";

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

LCDDisplay display(0x27, 16, 2);
LedRGB led(33, 26, 27);
Buzzer buzzer(14);

// Variável para armazenar o momento inicial
unsigned long startMillis = 0;
// Variável para controlar o estado do LED
bool isLedOn = false;

void ligarLed(const char* cor) {


  led.setColor(false, false, false);
  // Verifica se o LED está ligado
  if (!isLedOn) {
    // Liga o LED   
    if (strcmp(cor, "Vermelho") == 0) {
        led.setColor(true, false, false); // Vermelho
    } else if (strcmp(cor, "Verde") == 0) {
        led.setColor(false, true, false); // Verde
    } else if (strcmp(cor, "Azul") == 0) {
        led.setColor(false, false, true); // Azul
    }

    startMillis = millis();          // Armazena o tempo atual
    isLedOn = true;                  // Atualiza o estado do LED
    Serial.println("LED ligado!");
  }

  if (isLedOn && (millis() - startMillis >= 2000)) {
    // Desliga o LED
    led.setColor(false, false, false); // Desliga o LED
    isLedOn = false;                   // Atualiza o estado do LED
    Serial.println("LED desligado!");
  }
}

// Realiza a conexão com o Wifi 
void setupWifi() {
  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  display.showMessage("WiFi Conectado!");
  ligarLed("Azul");
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// Realiza a conexão com o Broker e define o callback
void setupBroker() {
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

}

// Cria função de reconexão com o Broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão com o Broker...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado ao Broker!");
      client.subscribe("flask/state");
      client.subscribe("flask/isensor");
    } else {
      Serial.print("Falha ao conectar. Código: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

// Cria função callback 
void callback(char* topic, byte* message, unsigned int length) {
  // Recebe mensagem dos tópicos inscritos
  Serial.print("Mensagem vinda do tópico: ");
  Serial.print(topic);
  Serial.print(". Payload: ");
  String messageReceived;

  // Constrói a mensagem recebida
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageReceived += (char)message[i];
  }
  Serial.println(messageReceived);
}

void setup() {
  Serial.begin(115200); // Comunicação principal com o computador
  led.init();        // Inicializa o LED RGB
  buzzer.init();     // Inicializa o buzzer
  display.init();    // Inicializa o display LCD
  setupWifi();
  setupBroker();
  while (!Serial);  
  delay(100);
  Serial.println("\n\nSensor de impressão digital da Adafruit - Cadastro");

  // Inicializar a segunda porta serial
  mySerial.begin(57600, SERIAL_8N1, 16, 17); // RX = GPIO16, TX = GPIO17

  // Iniciar o sensor de impressão digital
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Sensor de impressão digital encontrado!");
  } else {
    Serial.println("Sensor de impressão digital não encontrado :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Lendo os parâmetros do sensor"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("ID do sistema: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacidade: ")); Serial.println(finger.capacity);
  Serial.print(F("Nível de segurança: ")); Serial.println(finger.security_level);
  Serial.print(F("Endereço do dispositivo: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Tamanho do pacote: ")); Serial.println(finger.packet_len);
  Serial.print(F("Taxa de transmissão: ")); Serial.println(finger.baud_rate);
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop() {
  // Verifica a conexão com o MQTT
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  Serial.println("Pronto para cadastrar uma impressão digital!");
  Serial.println("Digite o número do ID (de 1 a 127) que você deseja salvar...");
  ligarLed("Azul");
  display.showMessage("Pronto para cadastrar");
  id = readnumber();
  if (id == 0) {
     return;
  }
  Serial.print("Cadastrando ID #");
  Serial.println(id);

  while (! getFingerprintEnroll() );
}

uint8_t getFingerprintEnroll() {

  int p = -1;
  Serial.print("Aguardando um dedo válido para cadastrar como #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagem capturada");
      ligarLed("Verde");
      buzzer.beep();
      display.showMessage("Imagem capturada");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      display.showMessage("Coloque o dedo....");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Erro de comunicação");
      ligarLed("Vermelho");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Erro ao capturar imagem");
      ligarLed("Vermelho");
      break;
    default:
      Serial.println("Erro desconhecido");
      ligarLed("Vermelho");
      break;
    }
  }

  // OK success!
  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagem convertida");
      ligarLed("Verde");
      buzzer.beep();
      display.showMessage("Imagem convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagem muito confusa");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Erro de comunicação");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Não foi possível encontrar características da impressão digital");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Imagem inválida");
      ligarLed("Vermelho");
      return p;
    default:
      Serial.println("Erro desconhecido");
      ligarLed("Vermelho");
      return p;
  }

  Serial.println("Remova o dedo");
  display.showMessage("Remova o dedo");

  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Coloque o mesmo dedo novamente");
  display.showMessage("Coloque o mesmo dedo");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagem capturada");
      ligarLed("Verde");
      buzzer.beep();
      display.showMessage("Imagem capturada");
      break;
    case FINGERPRINT_NOFINGER:
      display.showMessage("Coloque o dedo...");
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Erro de comunicação");
      ligarLed("Vermelho");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Erro ao capturar imagem");
      ligarLed("Vermelho");
      break;
    default:
      Serial.println("Erro desconhecido");
      ligarLed("Vermelho");
      break;
    }
  }

  // OK success!
  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Imagem convertida");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Imagem muito confusa");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Erro de comunicação");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Não foi possível encontrar características da impressão digital");
      ligarLed("Vermelho");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Imagem inválida");
      ligarLed("Vermelho");
      return p;
    default:
      Serial.println("Erro desconhecido");
      ligarLed("Vermelho");
      return p;
  }

  // OK converted!
  Serial.print("Criando modelo para #");  Serial.println(id);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Impressões correspondem!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Erro de comunicação");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("As impressões não correspondem");
    return p;
  } else {
    Serial.println("Erro desconhecido");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id);
  if (p == FINGERPRINT_OK) {
    Serial.println("Armazenado com sucesso!");
    display.showMessage("Armazenado com sucesso!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Erro de comunicação");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Não foi possível armazenar nessa localização");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Erro ao gravar na memória flash");
    return p;
  } else {
    Serial.println("Erro desconhecido");
    return p;
  }
  // Conversão de `id` para string antes de publicar
  char idStr[4]; // Buffer para armazenar a string do ID (suficiente para IDs de 0 a 127)
  sprintf(idStr, "%d", id); // Converte o número para uma string
    // Verifica a conexão com o MQTT
  if (!client.connected()) {
    reconnect();
    sendMessage(idStr);
  } else {
    sendMessage(idStr);
  }
  Serial.println("Cadastro realizado com sucesso!");
  display.showMessage("Cadastro realizado com sucesso!");
  ligarLed("Verde");
  buzzer.beep();
  return true;
}

void sendMessage(const char* msg) {
    if (client.connected()) {
        if (client.publish("exodia/cadastro", msg)) {
            Serial.print("Mensagem enviada: ");
            Serial.println(msg);
        } else {
            Serial.println("Erro ao publicar a mensagem (2)!");
        }
    } else {
        Serial.println("Cliente desconectado, tentando reconectar...");
        reconnect();
        if (client.connected()) {
            if (client.publish("exodia/cadastro", msg)) {
                Serial.print("Mensagem enviada após reconexão: ");
                Serial.println(msg);
            } else {
                Serial.println("Erro ao publicar a mensagem (3)!");
            }
        } else {
            Serial.println("Reconexão falhou!");
        }
    }
}

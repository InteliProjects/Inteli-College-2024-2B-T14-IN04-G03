#include <Adafruit_Fingerprint.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>


// Defina o hardware serial do ESP32 conectado ao sensor de digitais
#define RX_PIN 16 // RX do ESP32 conectado ao TX do sensor
#define TX_PIN 17 // TX do ESP32 conectado ao RX do sensor

HardwareSerial mySerial(1); // Usando Serial1 do ESP32
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


// Inicializando os objetos das classes das bibliotecas
WiFiClient wifiClient;
PubSubClient client(wifiClient);

// Constante das informações para conexão Wi-Fi
const char* ssid = "iPhone";
const char* password = "murilo123";

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

// Realiza a conexão com o Wifi 
void setupWifi() {


  Serial.println("Conectando ao Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  display.showMessage("WiFi Conectado");
  led.setColor(false, false, true);
  buzzer.beep();
}

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


// Realiza a conexão com o Broker e define o callback
void setupBroker() {
  client.setServer(mqtt_server, mqtt_port);

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

void setup() {
  // Inicializa a comunicação serial para debug
  Serial.begin(115200);
  led.init();        // Inicializa o LED RGB
  buzzer.init();     // Inicializa o buzzer
  display.init();    // Inicializa o display LCD

  setupWifi();
  setupBroker();
  while (!Serial);

  // Inicializa o hardware serial para o sensor de digitais
  mySerial.begin(57600, SERIAL_8N1, RX_PIN, TX_PIN);

  // Inicializa o sensor de digitais
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Sensor de digitais encontrado!");
  } else {
    Serial.println("Falha ao encontrar o sensor de digitais.");
    while (1) { delay(1); } // Trava o programa caso o sensor não seja encontrado
  }
}

void loop() {
  // Verifica a conexão com o MQTT
  if (!client.connected()) {
    reconnect();
  }
  Serial.println("Aproxime seu dedo para verificação...");
  ligarLed("Azul");
  display.showMessage("Aproxime seu dedo para verificação...");

  // Aguarda até que um dedo válido seja detectado
  int p = finger.getImage();
  if (p == FINGERPRINT_NOFINGER) {
    delay(100); // Sem dedo detectado, espera para verificar novamente
    return;
  } else if (p != FINGERPRINT_OK) {
    Serial.println("Erro ao capturar imagem da digital.");
    ligarLed("Vermelho");
    display.showMessage("Erro ao capturar imagem da digital.");
    return;
  }

  // Converte a imagem capturada em características
  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) {
    Serial.println("Erro ao processar a imagem da digital.");
    ligarLed("Vermelho");
    display.showMessage("Erro ao processar a imagem da digital.");
    return;
  }

  // Busca correspondência no banco de dados
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    // Caso a digital seja encontrada
    Serial.println("Digital reconhecida!");
    Serial.print("ID da digital: "); Serial.println(finger.fingerID);
    Serial.print("Confiança: "); Serial.println(finger.confidence);

    // Ação para digitais reconhecidas
    digitalRecognizedAction();

  } else if (p == FINGERPRINT_NOTFOUND) {
    // Caso a digital não seja encontrada
    Serial.println("Digital não encontrada.");    
    ligarLed("Vermelho");
    display.showMessage("Digital não encontrada.");

  } else {
    Serial.println("Erro na leitura da digital.");
    ligarLed("Vermelho");
    display.showMessage("Erro na leitura da digital.");
  }

  delay(1000); // Aguarda um segundo antes de permitir nova leitura
}

void digitalRecognizedAction() {
  Serial.println("Acesso permitido! Executando ação...");
  ligarLed("Verde");
  display.showMessage("Digital reconhecida!");
  // Aqui você pode adicionar ações, como ativar um LED ou abrir uma porta
}
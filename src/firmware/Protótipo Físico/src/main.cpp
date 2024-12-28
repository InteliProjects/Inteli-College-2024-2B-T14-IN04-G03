#include <Arduino.h>
#include "Biometrics.h"
#include "RFID.h"
#include "Display.h"
#include "Led.h"
#include <PubSubClient.h>
#include <WiFi.h>

// Iniciando objetos das bibliotecas
WiFiClientSecure espClient;
WiFiClient wifiClient;
PubSubClient client(espClient);

//Constantes de conexão com o Broker;
const int mqtt_port = 8883;
const char* mqtt_server = "848c6529c87c4961b45a47c5680c369e.s1.eu.hivemq.cloud";
const char* mqtt_user = "exodia";
const char* mqtt_pass = "Exodia#123";

//Constantes de conexão com a Internet;
const char* ssid = "iPhone"
const char* password = "murilo123"

//Realiza a conexão com o Wifi;
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
}

//Realiza a conexão com o Broker e define o callback;
void setupBroker() {
  espClient.setInsecure();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

//Cria função de reconexão com o Broker;
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão com o Broker...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("Conectado ao Broker!");
      client.subscribe("exodia/rfid");
      client.subscribe("exodia/biometria");
    } else {
      Serial.print("Falha ao conectar. Return Code: ");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void sendMessage(String topic, String msg) {
  if (client.publish(topic1.c_str(), msg.c_str())) {
      Serial.print("Mensagem enviada: ");
      Serial.println(msg);
    } else {
      Serial.println("Erro ao enviar a mensagem (1)!");
    }
}

//Cria função callback;
void callback(char* topic, byte* message, unsigned int length) {
  //Recebe mensagem dos tópicos inscritos;
  Serial.print("Mensagem vinda do tópico: ");
  Serial.println(topic);
  Serial.print("Payload: ");
  String messageReceived;
  //Constrói a mensagem recebida;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageReceived += (char)message[i];
  }
  Serial.println(messageReceived);
}


// BIOMETRIA - Definição dos pinos e criação das instâncias das classes
const int RX_PIN = 16; // Corrigir (pino incorreto)
const int TX_PIN = 17; // Corrigir (pino incorreto)

HardwareSerial fingerprintSerial(2);
Biometrics biometrics(fingerprintSerial);

// RFID - Definição dos pinos e criação das instâncias das classes
const int SS_PIN = 5; // Corrigir (pino incorreto)
const int RST_PIN = 22; // Corrigir (pino incorreto)

RFID rfid(SS_PIN, RST_PIN);
Led led;
Display display;

bool onlyRead = true;

void setup() {
  Serial.begin(115200);
  fingerprintSerial.begin(57600, SERIAL_8N1, RX_PIN, TX_PIN);
  setupWifi();
  setupBroker();
  sendMessage("exodia/esp", "ESP Conectado!")

  led.setup();
  display.setup();
  biometrics.setup();
  rfid.setup();
}

void loop() {
  //Verifica se o cliente (ESP32) está conectado com o Broker
  if (!client.connected()) {
    reconnect();
    }
  client.loop();

  if (onlyRead) {
    // if (biometrics.isFingerDetected()) {
      // Serial.println("Digital detectada, iniciando autenticação");
      biometrics.readFingerprint();
    // }

    if (rfid.isRfidDetected()) {
      Serial.println("Token RFID detectado, iniciando autenticação");
      rfid.readRfid();
    }

    delay(100);
  } else {
    // Lógica de cadastro
    // if (biometrics.isFingerDetected()) {
      // Serial.println("Digital detectada, iniciando cadastro");
      biometrics.registerFingerprint();
    // }

    if (rfid.isRfidDetected()) {
      Serial.println("Token RFID detectado, iniciando cadastro");
      rfid.registerRfid();
    }

    // Tem que fazer alguma lógica para receber do front se a pessoa quer cadastrar
    // a biometria ou um token RFIDMQTT_TLS_ENABLED
  }
}

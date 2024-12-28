// Define variáveis para consulta e análise atual de estado
byte ledsOn[] = {0, 0, 0};

// Define as portas dos componentes
const byte slideSwitch = 13;
const byte ledPins[] = {0, 2, 15};
const byte greenButton = 19;
const byte redButton = 18;
const byte blueButton = 5;
const byte buzzer = 33;

// Define variáveis relacionadas ao intervalo de acender os Leds
unsigned long previousLedTime[] = {0, 0, 0};
const unsigned long ledInterval = 1000;

// Define variáveis booleanas para conferir estados
bool isBiometrics;
bool isRegistration;
bool previousSwitchState = HIGH;

// Função resposável por desligar os Leds Automáticamente
void turnOffLeds() {
  unsigned long currentTime = millis();
  for (int i = 0; i < 3; i++) {
    if (ledsOn[i] && (currentTime - previousLedTime[i] >= ledInterval)) {
      digitalWrite(ledPins[i], LOW);
      ledsOn[i] = 0;
    }
  }
}

// Função resposável por desligar o Led escolhido pelo parâmetro acompanhado
void turnOnLed(int ledNumber) {
  if (!ledsOn[ledNumber]) {
    digitalWrite(ledPins[ledNumber], HIGH);
    ledsOn[ledNumber] = 1;
    previousLedTime[ledNumber] = millis();
  }
}

// Função resposável por alterar o estado de Cadastro para Leitura e vice-versa
void trocarFuncao() {
  isRegistration = !isRegistration;
  turnOnLed(2);
  Serial.print("Função atual:");
  Serial.println(isRegistration ? "Cadastrar" : "Ler");
}

// Cria uma classe de Biometria
class Biometrics {
  public:
    Biometrics();
    // Métodos da função que recebem parâmetros booleanos
    void registerBiometrics(bool success);
    void readBiometrics(bool success);
};

// Construtor padrão da Classe
Biometrics::Biometrics() {}

// Define o método da classe lerBiometria Biometria que permite ver se a biometria foi resgistrada com sucesso
void Biometrics::registerBiometrics(bool success) {
  if (success) {
    turnOnLed(1);
    tone(buzzer, 262, 250);
    Serial.println("Biometria registrada com sucesso!");
  } else {
    turnOnLed(0);
    tone(buzzer, 131, 250);
    Serial.println("Falha no registro da biometria.");
  }
}

// Define o método lerBiometria da classe Biometria que permite ver se a biometria foi lida com sucesso
void Biometrics::readBiometrics(bool success) {
  if (success) {
    turnOnLed(1);
    tone(buzzer, 262, 250);
    Serial.println("Biometria lida com sucesso!");
  } else {
    turnOnLed(0);
    tone(buzzer, 131, 250);
    Serial.println("Falha na leitura da biometria.");
  }
}

// Cria a classe RFID
class RFID {
  public:
    RFID();
    void registerCard(bool success);
    void readCard(bool success);
};

// Construtor padrão da classe
RFID::RFID() {}

// Define o método registrarCartão da classe RFID que permite ver se o cartão foi registrado com sucesso
void RFID::registerCard(bool success) {
  if (success) {
    turnOnLed(1);
    tone(buzzer, 262, 250);
    Serial.println("Cartão registrado com sucesso!");
  } else {
    turnOnLed(0);
    tone(buzzer, 131, 250);
    Serial.println("Falha no registro do cartão.");
  }
}

// Define o método lerCartão da classe RFID que permite ver se o cartão foi lido com sucesso
void RFID::readCard(bool success) {
  if (success) {
    turnOnLed(1);
    tone(buzzer, 262, 250);
    Serial.println("Cartão lido com sucesso!");
  } else {
    turnOnLed(0);
    tone(buzzer, 131, 250);
    Serial.println("Falha na leitura do cartão.");
  }
}

// Inicialização de objetos 
Biometrics biometrics;
RFID rfid;

// Configura as portas dos componentes no ESP32
void setup() {
  for (int i = 0; i < 3; i++) pinMode(ledPins[i], OUTPUT);
  pinMode(slideSwitch, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(redButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

// Função que ficará em loop
void loop() {
  // Define que ao usar o Switch ele irá alterar o estado de uma variável booleana
  bool currentSwitchState = digitalRead(slideSwitch); // Variável de controle
  
  /* Se o estado do Switch foi alterado a função irá
    trocar a classe de Biometria para RFID
  */
  if (currentSwitchState != previousSwitchState) {
    Serial.print("O switch foi alterado para: ");
    Serial.println(currentSwitchState == LOW ? "Biometria" : "RFID");

    previousSwitchState = currentSwitchState;
  }

  // Caso o Switch esteja em estado LOW, será Biometria
  isBiometrics = digitalRead(slideSwitch) == LOW;

  // Condicional para ativar a troca de função de cadastro para leitura ou leitura para cadastro
  if (digitalRead(blueButton) == LOW) {
    trocarFuncao();
    tone(buzzer, 400, 250);
    delay(1000);
  }

  // Condicional que confere se a variável de controle é verdadeira ou falsa
  if (isBiometrics) {

    /* Condicional para acionar as funções de resgistrarBiometria e lerBiometria
    caso aperte o botão verde ou vermelho */
    if (digitalRead(greenButton) == LOW) {
      isRegistration ? biometrics.registerBiometrics(true) : biometrics.readBiometrics(true);
      delay(1000);
    }
    if (digitalRead(redButton) == LOW) {
      isRegistration ? biometrics.registerBiometrics(false) : biometrics.readBiometrics(false);
      delay(1000);
    }
  } else {
    /* Condicional para acionar as funções de resgistrarCartão e lerCartão
    caso aperte o botão verde ou vermelho */
    if (digitalRead(greenButton) == LOW) {
      isRegistration ? rfid.registerCard(true) : rfid.readCard(true);
      delay(1000);
    }
    if (digitalRead(redButton) == LOW) {
      isRegistration ? rfid.registerCard(false) : rfid.readCard(false);
      delay(1000);
    }
  }

  // Aciona a função de desligar os leds
  turnOffLeds();
  
  // Realiza uma pausa de 15 segundos no loop
  delay(15);
}

#include <Arduino.h>
#include "Buzzer.h"

// Construtor da classe Buzzer
Buzzer::Buzzer() : buzzerPin(buzzerPin) {}

// Função de configuração do pino do buzzer
void Buzzer::setup() {
    pinMode(buzzerPin, OUTPUT);
}

// Função para tocar um som no buzzer
void Buzzer::playSound(int soundTone, int period) {
    tone(buzzerPin, soundTone, period);
}

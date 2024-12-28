#include "Led.h"

// Construtor da classe Led
Led::Led() : startTime(0), period(0) {}

// Função para configurar os Led's
void Led::setup() {
    pinMode(ledRed, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledBlue, OUTPUT);
    turnOffLed();
}

// Função para ligar o led em certa cor determinada
void Led::writeToLed(int ledRedValue, int ledGreenValue, int ledBlueValue) {
    analogWrite(ledRed, ledRedValue);
    analogWrite(ledGreen, ledGreenValue);
    analogWrite(ledBlue, ledBlueValue);
}

// Liga o LED na cor especificada e define o período de tempo em milissegundos
void Led::turnOnLed(LedColor color, int period) {
    switch (color) {
        case RED:
            writeToLed(255, 0, 0);
            break;
        case GREEN:
            writeToLed(0, 255, 0);
            break;
        case BLUE:
            writeToLed(0, 0, 255);
            break;
        default:
            turnOffLed();
            break;
    }
    
    if (period > 0) {
        this->period = period;
        if (startTime == 0) startTime = millis();
    }
}

// Função para desligar totalmente o Led
void Led::turnOffLed() {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledBlue, LOW);
    startTime = 0;
    period = 0;
}

// Função que permite o Led funcionar com millis
void Led::update() {
    if (period > 0 && millis() - startTime >= period) {
        turnOffLed();
    }
}

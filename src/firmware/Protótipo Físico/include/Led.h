#ifndef LED_H
#define LED_H

#include <Arduino.h>

enum LedColor {
    RED,
    GREEN,
    BLUE
};

// Classe que representa um LED com três cores (vermelho, verde e azul)
class Led {
private:
    // Pino do LED vermelho
    const int ledRed = 33;
    // Pino do LED verde
    const int ledGreen = 26;
    // Pino do LED azul
    const int ledBlue = 27;
    // Tempo de início para controle de temporização
    unsigned long startTime;
    // Período para controle de temporização
    int period;

public:
    // Construtor da classe Led
    Led();
    // Configura os pinos do LED
    void setup();
    // Escreve valores nos LEDs
    void writeToLed(int ledRedValue, int ledGreenValue, int ledBlueValue);
    // Liga o LED de uma cor específica por um período opcional
    void turnOnLed(LedColor color, int period = 0);
    // Desliga o LED
    void turnOffLed();
    // Atualiza o estado do LED
    void update();
};

#endif
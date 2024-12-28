#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Classe que gerencia o display LCD
class Display {
private:
    LiquidCrystal_I2C lcd; // Objeto para controlar o display LCD
    unsigned long startTime; // Tempo de início para controle de tempo
    int period; // Período para atualização do display

public:
    Display(); // Construtor da classe Display
    void setup(); // Configura o display
    void writeMessage(const char* message1, const char* message2 = "", int period = 0); // Escreve uma mensagem no display
    void clearDisplay(); // Limpa o display
    void update(); // Atualiza o display periodicamente
};

#endif

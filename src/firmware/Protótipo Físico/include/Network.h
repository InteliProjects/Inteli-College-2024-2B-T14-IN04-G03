#ifndef NETWORK_H
#define NETWORK_H

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

// Classe para gerenciar conexões de rede WiFi
class Network {
    private:
        String networkRssi = ""; // Armazena a intensidade do sinal da rede
        String networkPassword = ""; // Armazena a senha da rede
    
    public:
        Network(); // Construtor da classe Network
        void scanNetworks(); // Função para escanear redes WiFi disponíveis
        void connectToNetwork(); // Função para conectar à rede WiFi com maior potência
};

#endif
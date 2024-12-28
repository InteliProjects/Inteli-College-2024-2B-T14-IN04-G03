#ifndef RFID_H
#define RFID_H

#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <vector>
#include <string>
#include "Led.h"
#include "Display.h"
#include "Lock.h"

// Classe para manipulação do sensor RFID
class RFID {
    private:
        std::vector<String> authorizedUids; // Lista de UIDs autorizados
        String lastCardUID; // UID do último cartão lido

        MFRC522 rfid; // Objeto para manipulação do sensor RFID
        Display display; // Objeto para manipulação do display
        Led led; // Objeto para manipulação do LED

        // Gera um hash aleatório para atribuir ao cartão
        String generateRandomHash();

        // Grava o hash no cartão RFID
        bool writeHashToCard(const String &hash);

    public:
        RFID(byte ssPin, byte rstPin); // Construtor da classe RFID
        void setup(); // Configura o sensor RFID
        bool isRfidDetected(); // Verifica se há um cartão detectado
        void readRfid(); // Lê e processa o cartão RFID
        void registerRfid(); // Registra um novo cartão RFID
        String getRfidUID(); // Retorna o UID do cartão detectado
        bool isAuthorized(const String &uid); // Verifica se o cartão é autorizado
};

#endif
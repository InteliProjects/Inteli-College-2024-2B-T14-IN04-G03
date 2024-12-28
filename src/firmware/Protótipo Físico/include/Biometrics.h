#ifndef BIOMETRICS_H
#define BIOMETRICS_H

#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include "Led.h"
#include "Display.h"
#include "Lock.h"

class Biometrics {
    private:
        // Objeto para manipulação do sensor de impressão digital
        Adafruit_Fingerprint fingerprint;
        // Função para obter o ID da impressão digital
        uint8_t getFingerprintID();
    
    protected:
        // Objeto para controle do LED
        Led led = Led();
        // Objeto para controle do display
        Display display = Display();
        // Objeto para controle da fechadura
        Lock lock = Lock();
        // Função para encontrar um ID disponível
        int findAvailableID();

    public:
        // Construtor que inicializa a biometria com a serial fornecida
        Biometrics(Stream &serial);
        // Função de configuração inicial
        void setup();
        // Função para verificar se um dedo foi detectado
        bool isFingerDetected();
        // Função para ler a impressão digital
        void readFingerprint();
        // Função para registrar uma nova impressão digital
        void registerFingerprint();
};

#endif
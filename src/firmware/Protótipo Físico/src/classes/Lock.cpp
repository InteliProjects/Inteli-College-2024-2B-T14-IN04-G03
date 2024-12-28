#include "Lock.h"
#include <Arduino.h>

// Construtor da classe Lock
Lock::Lock() : lock(22) {}

// Função para configurar o relé/trava eletrônica
void Lock::setup() {
    pinMode(lock, OUTPUT);
}

// Função que altera o estado do cadeado.
void Lock::changeLockState(bool isOpen) {
    digitalWrite(lock, isOpen ? HIGH : LOW);
}

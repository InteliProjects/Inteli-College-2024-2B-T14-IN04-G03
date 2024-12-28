#ifndef LOCK_H
#define LOCK_H

// Classe que representa uma trava
class Lock {
    private:
        int lock = 0; // Pino da trava

    public:
        // Construtor da classe Lock
        Lock();
        // Configurações iniciais da trava
        void setup();
        // Altera o estado da trava (aberta ou fechada)
        void changeLockState(bool isOpen);
};

#endif
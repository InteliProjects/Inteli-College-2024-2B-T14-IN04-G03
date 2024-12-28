#ifndef BUZZER_H
#define BUZZER_H

// Classe que representa um Buzzer
class Buzzer {
    private:
        // Pino do Buzzer
        const int buzzerPin = 25;
    
    public:
        // Construtor da classe Buzzer
        Buzzer();
        // Configurações iniciais do Buzzer
        void setup();
        // Toca um som no Buzzer
        void playSound(int soundTone, int period = 1000);
};

#endif
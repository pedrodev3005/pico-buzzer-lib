// EXEMPLO_BUZZER_INIT

#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h" //mude para o caminho onde esta sua biblioteca.

#define BUZZER_PIN 21

int main() {
    stdio_init_all();
    sleep_ms(3000);

    Buzzer buzzer;
    buzzer_init(&buzzer, BUZZER_PIN, 1000);

    printf("Teste de inicialização: Buzzer no pino %d com frequência %d Hz\n", buzzer.pin, buzzer.frequency);
    
    buzzer_on(&buzzer);
    while (1) {
        sleep_ms(1000);
    }

    return 0;
}

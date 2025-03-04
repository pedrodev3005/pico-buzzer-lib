// EXEMPLO_BUZZER_BEEP

#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h" //mude para o caminho onde esta sua biblioteca.

#define BUZZER_PIN 21

int main() {
    stdio_init_all();
    sleep_ms(3000); //Delay para poder conectar o monitor serial

    Buzzer buzzer;
    buzzer_init(&buzzer, BUZZER_PIN, 1000);

    printf("Emitindo beep...\n");
    buzzer_beep(&buzzer, 500, 500);

    while (true)
    {
        /* você pode rodar outras coisas enquanto o beep é acionado*/
        printf("exemplo \n");
    }
    

    return 0;
}

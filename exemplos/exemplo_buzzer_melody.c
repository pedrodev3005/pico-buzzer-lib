// EXEMPLO_BUZZER_MELODY

#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h" //mude para o caminho onde esta sua biblioteca.

#define BUZZER_PIN 21

int main() {
    stdio_init_all();
    sleep_ms(3000); //Delay para poder conectar o monitor serial

    Buzzer buzzer1;
    buzzer_init(&buzzer1, 21, 1000);

    const uint melody_notes[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659};
    const uint melody_durations[] = {300, 300, 600, 300, 300, 600, 300, 300, 300, 300, 900};
    const uint melody_length = sizeof(melody_notes) / sizeof(melody_notes[0]);

    buzzer_melody(&buzzer1, melody_notes, melody_durations, melody_length);

    while (true) {
        // Seu código principal pode continuar rodando aqui
        printf("Executando outras tarefas...\n");
        sleep_ms(500);
    }

    return 0;
}
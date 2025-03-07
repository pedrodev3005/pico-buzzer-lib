// EXEMPLO_BUZZER_SET/GET_FREQUENCY

#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h" //mude para o caminho onde esta sua biblioteca.

#define BUZZER_PIN 21

int main() {
    stdio_init_all();
    sleep_ms(3000); //Delay para poder conectar o monitor serial

    Buzzer buzzer;
    buzzer_init(&buzzer, BUZZER_PIN, 1000);
    buzzer_on(&buzzer);

    printf("Frequência inicial: %d Hz\n", buzzer_get_frequency(&buzzer));
    sleep_ms(1000);

    buzzer_set_frequency(&buzzer, 2000);
    printf("Frequência alterada para: %d Hz\n", buzzer_get_frequency(&buzzer));

    sleep_ms(1000);
    buzzer_off(&buzzer);

    return 0;
}

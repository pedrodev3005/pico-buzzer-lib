// EXEMPLO_BUZZER_SET/GET_VOLUME

#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h" //mude para o caminho onde esta sua biblioteca.

#define BUZZER_PIN 21

int main() {
    stdio_init_all();
    sleep_ms(3000); //Delay para poder conectar o monitor serial

    Buzzer buzzer;
    buzzer_init(&buzzer, BUZZER_PIN, 1000);

    printf("Definindo volume para 20%%\n");
    buzzer_set_volume(&buzzer, 20);
    printf("Volume atual: %d\n", buzzer_get_level(&buzzer));
    buzzer_on(&buzzer);
    sleep_ms(1000);
    buzzer_off(&buzzer);

    printf("Definindo volume para 80%%\n");
    buzzer_set_volume(&buzzer, 80);
    printf("Volume atual em pwm: %d\n", buzzer_get_level(&buzzer));
    buzzer_on(&buzzer);
    sleep_ms(1000);
    buzzer_off(&buzzer);

    return 0;
}
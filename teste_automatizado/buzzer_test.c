#include <stdio.h>
#include "pico/stdlib.h"
#include "buzzer.h"

#define TEST_BUZZER_PIN 21

#define MAX_PWM 4096

void test_buzzer_init() {
    printf("Testando buzzer_init...\n");
    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000); // 1kHz

    if (buzzer.pin != TEST_BUZZER_PIN || buzzer.frequency != 1000) {
        printf("FALHOU: Inicialização incorreta.\n");
    }

    printf("PASSOU\n");
}

void test_buzzer_frequency() {
    printf("Testando buzzer_set_frequency e buzzer_get_frequency...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    buzzer_set_frequency(&buzzer, 2000);
    if (buzzer_get_frequency(&buzzer) != 2000) {
        printf("FALHOU: Frequência não foi alterada corretamente.\n");
    }

    printf("PASSOU\n");
}

void test_buzzer_volume() {
    printf("Testando buzzer_set_volume e buzzer_get_level...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    buzzer_set_volume(&buzzer, 75);
    if (buzzer_get_level(&buzzer) != (75 * MAX_PWM) / 100) {
        printf("FALHOU: Volume não foi ajustado corretamente.\n");
    }

    printf("PASSOU\n");
}

void test_buzzer_beep() {
    printf("Testando buzzer_beep...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    buzzer_beep(&buzzer, 500, 200);
    sleep_ms(700); // Espera a execução do beep e pausa

    printf("PASSOU\n");
}

void test_buzzer_beep_no_interruption() {
    printf("Testando buzzer_beep_no_interruption...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    buzzer_beep_no_interruption(&buzzer, 500, 200);

    printf("PASSOU\n");
}

void test_buzzer_on_off() {
    printf("Testando buzzer_on e buzzer_off...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);
    // **Ligar o buzzer**
    buzzer_on(&buzzer);
    uint level_on = buzzer_get_level(&buzzer);
    if (level_on == 0) {
        printf("FALHOU: Buzzer deveria estar ligado, mas o nível de PWM é 0.\n");
    } else {
        printf("Buzzer ligado com PWM = %d\n", level_on);
    }

    sleep_ms(2000);
    // **Desligar o buzzer**
    buzzer_off(&buzzer);
    sleep_ms(2000);
    uint level_off = buzzer_get_level(&buzzer);
    if (level_off != 0) {
        printf("FALHOU: Buzzer deveria estar desligado, mas o nível de PWM é %d.\n", level_off);
    } else {
        printf("Buzzer desligado corretamente.\n");
    }

    printf("PASSOU\n");
}


void test_buzzer_melody() {
    printf("Testando buzzer_melody...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    const uint melody_notes[] = {262, 294, 330, 349, 392}; // Dó Ré Mi Fá Sol
    const uint melody_durations[] = {500, 500, 500, 500, 500};

    buzzer_melody(&buzzer, melody_notes, melody_durations, 5);
    
    sleep_ms(3000); // Espera a melodia terminar

    printf("PASSOU\n");
}

void test_buzzer_melody_no_interruption() {
    printf("Testando buzzer_melody_no_interruption...\n");

    Buzzer buzzer;
    buzzer_init(&buzzer, TEST_BUZZER_PIN, 1000);

    const uint melody_notes[] = {262, 294, 330, 349, 392}; // Dó Ré Mi Fá Sol
    const uint melody_durations[] = {500, 500, 500, 500, 500};

    buzzer_melody_no_interruption(&buzzer, melody_notes, melody_durations, 5);

    printf("PASSOU\n");
}

int main() {
    stdio_init_all();
    sleep_ms(2000); // Espera inicial para inicializar o console
    
    test_buzzer_init();
    sleep_ms(50);
    test_buzzer_frequency();
    sleep_ms(50);
    test_buzzer_volume();
    sleep_ms(50);
    test_buzzer_beep();
    sleep_ms(50);
    test_buzzer_beep_no_interruption();
    sleep_ms(50);
    test_buzzer_on_off();
    sleep_ms(50);
    test_buzzer_melody();
    sleep_ms(50);
    test_buzzer_melody_no_interruption();

    printf("\nTodos os testes concluídos.\n");
    return 0;
}

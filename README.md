## 📢 Pico Buzzer Library

Uma biblioteca em C para controlar buzzers passivos utilizando a **Raspberry Pi Pico** e placas baseadas no **RP2040**. Permite controlar **frequência, volume, emissão de beeps e execução de melodias**, com suporte opcional a **interrupções** para execução assíncrona.  

## 🚀 Recursos

✅ Controle de frequência e volume do buzzer  
✅ Emissão de beeps com duração e pausa configuráveis  
✅ Reprodução de melodias de forma síncrona ou assíncrona  
✅ Suporte a **interrupções** para execução não bloqueante  

---

## 📦 Instalação

1️⃣ **Clone o repositório** no seu ambiente de desenvolvimento:
   ```sh
   git clone https://github.com/seu-usuario/pico-buzzer-lib.git
   cd pico-buzzer-lib
   ```

2️⃣ **Adicione a biblioteca ao seu projeto**:  
   No seu `CMakeLists.txt`, inclua:
   ```cmake
   add_subdirectory(pico-buzzer-lib)
   target_link_libraries(seu_projeto pico-buzzer-lib)
   ```

3️⃣ **Inclua o cabeçalho no seu código C**:
   ```c
   #include "buzzer.h"
   ```

---

## 🛠️ Como Usar

### 🔹 Inicializando o Buzzer
```c
Buzzer buzzer;
buzzer_init(&buzzer, 21, 1000);  // Pino 21, 1000 Hz
```

### 🔹 Emitindo um beep
```c
buzzer_beep(&buzzer, 500, 200); // Beep de 500ms, pausa de 200ms
```

### 🔹 Definindo frequência e volume
```c
buzzer_set_frequency(&buzzer, 1500); // Muda para 1500 Hz
buzzer_set_volume(&buzzer, 75);      // Define volume para 75%
```

### 🔹 Executando uma melodia
```c
const uint melody_notes[] = {659, 659, 659, 784, 659, 587, 523};
const uint melody_durations[] = {300, 300, 300, 600, 300, 300, 900};

buzzer_melody(&buzzer, melody_notes, melody_durations, 7);
```

---

## 📝 Exemplo Completo

```c
#include "buzzer.h"
#include <stdio.h>

Buzzer buzzer;

int main() {
    stdio_init_all();
    buzzer_init(&buzzer, 21, 1000);

    printf("Iniciando teste do buzzer...\n");

    buzzer_beep(&buzzer, 500, 200);
    buzzer_set_frequency(&buzzer, 1500);
    buzzer_set_volume(&buzzer, 80);

    const uint melody_notes[] = {659, 659, 784, 659, 523};
    const uint melody_durations[] = {300, 300, 600, 300, 900};

    buzzer_melody(&buzzer, melody_notes, melody_durations, 5);

    return 0;
}
```

---

## 🎵 Melodias de Exemplo

🎶 **Jingle Bells**  
```c
const uint melody_notes[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659};
const uint melody_durations[] = {300, 300, 600, 300, 300, 600, 300, 300, 300, 300, 900};

buzzer_melody(&buzzer, melody_notes, melody_durations, 11);
```

📌 **Quer adicionar mais músicas?** Basta criar novas arrays de notas e durações! 🎼

---

## 🔗 Contribuindo

Sinta-se à vontade para **abrir issues e pull requests** no repositório!  
Qualquer melhoria, nova funcionalidade ou correção de bugs são bem-vindas. 😃

---

## 📄 Licença

Este projeto está sob a licença **MIT**, permitindo uso, modificação e distribuição livremente. 📜

---

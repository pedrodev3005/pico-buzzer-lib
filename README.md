## 📢 Pico Buzzer Library

Uma biblioteca em C para controlar buzzers passivos utilizando a **Raspberry Pi Pico** e placas baseadas no **RP2040**. Permite controlar **frequência, volume, emissão de beeps e execução de melodias**, com suporte opcional a **interrupções** para execução assíncrona.  

---

## 📂 Estrutura do Projeto

```
📁 Código_fonte      # Biblioteca do buzzer
│── 📁 inc          # Arquivos de cabeçalho
│   ├── buzzer.h
│
│── 📁 src          # Implementação da biblioteca
│   ├── buzzer.c
│
│── README.md       # Documentação do projeto
│
📁 exemplos          # Exemplos de uso da biblioteca (cada subpasta é um projeto independente)
│── 📁 buzzer_beep                   # Teste da função buzzer_beep()
│── 📁 buzzer_melody                 # Teste da função buzzer_melody()
│── 📁 buzzer_melody_no_interruption # Teste da função buzzer_melody sem interrupção
│── 📁 buzzer_set_e_get_frequency    # Teste das funções de set/get frequência
│── 📁 buzzer_set_e_get_volume       # Teste das funções de set/get volume
```

✅ **`Código_fonte/`** → Contém os arquivos principais da biblioteca (`buzzer.h` e `buzzer.c`)  
✅ **`exemplos/`** → Contém projetos individuais para testar cada funcionalidade do buzzer  

---

## 🚀 Recursos

✅ Controle de **frequência e volume** do buzzer  
✅ Emissão de **beeps** com duração e pausa configuráveis  
✅ Reprodução de **melodias** de forma síncrona ou assíncrona  
✅ Suporte a **interrupções** para execução não bloqueante  

---

## 🛠️ Como Rodar os Exemplos  

### 🔹 1️⃣ Instale a Extensão da Raspberry Pi no VS Code  
Se ainda não tiver instalado, adicione a extensão **"Raspberry Pi Pico - C/C++ Project"** no **VS Code**.

### 🔹 2️⃣ Importe o Exemplo Desejado  
1. No VS Code, clique em **"Importar Projeto"**  
2. Selecione a **pasta do exemplo** dentro de `exemplos/`  
3. Compile e **grave no microcontrolador** 🚀  

**Exemplo:**
Se quiser testar a função `buzzer_beep`, importe:  
📂 `exemplos/buzzer_beep`

---


## 📜 Exemplo de Uso  

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
const uint melody_notes[] = {659, 659, 784, 659, 523};
const uint melody_durations[] = {300, 300, 600, 300, 900};

buzzer_melody(&buzzer, melody_notes, melody_durations, 5);
```

---

## 🎵 Melodias de Exemplo  

🎶 **Jingle Bells**  
```c
const uint melody_notes[] = {659, 659, 659, 784, 659, 587, 523};
const uint melody_durations[] = {300, 300, 300, 600, 300, 300, 900};

buzzer_melody(&buzzer, melody_notes, melody_durations, 7);
```

---

## 🔗 Contribuindo  

Sinta-se à vontade para **abrir issues e pull requests** no repositório!  
Qualquer melhoria, nova funcionalidade ou correção de bugs são bem-vindas. 😃  

---

## 📄 Licença  

Este projeto está sob a licença **MIT**, permitindo uso, modificação e distribuição livremente. 📜  

---

// Sistema de Monitoramento de Temperatura com Indicador Visual por LEDs
// Nome: Adilson

#include <stdio.h>          // Biblioteca para entrada e saída padrão (printf, scanf)
#include <stdlib.h>         // Biblioteca para funções padrão, incluindo geração de números aleatórios
#include "pico/stdlib.h"    // Biblioteca do Raspberry Pi Pico para controle de hardware
#include "hardware/uart.h"  // Biblioteca para comunicação serial via UART

// ---------------------------- CONFIGURAÇÃO DA UART ----------------------------
#define UART_ID uart1       // Define a UART que será utilizada (UART1)
#define BAUD_RATE 115200    // Define a taxa de transmissão de dados (115200 bps)
#define UART_TX_PIN 4       // Define o pino GPIO 4 como TX (Transmissão)
#define UART_RX_PIN 5       // Define o pino GPIO 5 como RX (Recepção)

// ---------------------------- CONFIGURAÇÃO DOS LEDs ----------------------------
#define LED_RED_PIN 13    // Pino do LED vermelho (GP13) - Indica temperatura entre 30°C e 45°C
#define LED_BLUE_PIN 12   // Pino do LED azul (GP12) - Indica temperatura entre 21°C e 29°C
#define LED_GREEN_PIN 11  // Pino do LED verde (GP11) - Indica temperatura entre 17°C e 20°C

// ---------------------------- DEFINIÇÃO DOS LIMITES DE TEMPERATURA ----------------------------
#define TEMP_VERMELHO_MIN 30.0f  // Temperatura mínima para acionar o LED vermelho
#define TEMP_VERMELHO_MAX 45.0f  // Temperatura máxima para acionar o LED vermelho
#define TEMP_AZUL_MIN 21.0f      // Temperatura mínima para acionar o LED azul
#define TEMP_AZUL_MAX 29.0f      // Temperatura máxima para acionar o LED azul
#define TEMP_VERDE_MIN 17.0f      // Temperatura mínima para acionar o LED verde
#define TEMP_VERDE_MAX 20.0f      // Temperatura máxima para acionar o LED verde

// ---------------------------- SIMULAÇÃO DA LEITURA DE TEMPERATURA ----------------------------
/*
 * Esta função simula a leitura de temperatura, retornando um valor aleatório entre 17.0°C e 45.0°C.
 * O cálculo funciona da seguinte forma:
 * - `rand() % 280` gera um número inteiro entre 0 e 279.
 * - Dividindo por 10.0f, obtemos um número decimal entre 0.0 e 27.9.
 * - Somando 17.0f, garantimos que a temperatura esteja dentro do intervalo desejado.
 */
float read_temperature() {
    return 17.0f + (rand() % 280) / 10.0f; 
}

// ---------------------------- FUNÇÃO DE INICIALIZAÇÃO DOS LEDs ----------------------------
/*
 * Configura os pinos dos LEDs como saída e garante que todos iniciem apagados.
 */
void init_leds() {
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_put(LED_RED_PIN, 0);  // Desliga o LED vermelho

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_put(LED_BLUE_PIN, 0); // Desliga o LED azul

    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_put(LED_GREEN_PIN, 0); // Desliga o LED verde
}

// ---------------------------- FUNÇÃO DE CONTROLE DOS LEDs ----------------------------
/*
 * Acende um LED de acordo com a faixa de temperatura lida:
 * - Se a temperatura estiver entre 30°C e 45°C, acende o LED vermelho.
 * - Se estiver entre 21°C e 29°C, acende o LED azul.
 * - Se estiver entre 17°C e 20°C, acende o LED verde.
 * - Se estiver fora dessas faixas, todos os LEDs permanecem apagados.
 */
void control_leds(float temperature) {
    // Apaga todos os LEDs antes de verificar a temperatura
    gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_BLUE_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);

    if (temperature >= TEMP_VERMELHO_MIN && temperature <= TEMP_VERMELHO_MAX) {
        gpio_put(LED_RED_PIN, 1);  // Liga o LED vermelho
        printf("[LED] Vermelho ligado (%.1f°C)\n", temperature);
        printf("Temperatura está acima do permitido!\n"); // Mensagem adicional de alerta
    } 
    else if (temperature >= TEMP_AZUL_MIN && temperature <= TEMP_AZUL_MAX) {
        gpio_put(LED_BLUE_PIN, 1);  // Liga o LED azul
        printf("[LED] Azul ligado (%.1f°C)\n", temperature);
    } 
    else if (temperature >= TEMP_VERDE_MIN && temperature <= TEMP_VERDE_MAX) {
        gpio_put(LED_GREEN_PIN, 1);  // Liga o LED verde
        printf("[LED] Verde ligado (%.1f°C)\n", temperature);
    } 
    else {
        printf("[LED] Nenhum LED ligado (%.1f°C)\n", temperature);  // Nenhum LED será aceso
    }
}

// ---------------------------- FUNÇÃO PRINCIPAL ----------------------------
/*
 * O programa inicializa a comunicação serial, configura os LEDs e entra em um loop infinito onde:
 * - Lê a temperatura simulada.
 * - Determina qual LED deve ser aceso com base na temperatura.
 * - Aguarda 9 segundos antes de repetir o ciclo.
 */
int main() {
    stdio_init_all();  // Inicializa a comunicação UART para saída no console
    init_leds();       // Configura os LEDs

    while (true) {
        float temperature = read_temperature();  // Obtém a temperatura simulada
        printf("--> Temperatura lida: %.1f°C\n", temperature);
        control_leds(temperature);  // Atualiza os LEDs conforme a temperatura
        sleep_ms(9000);  // Aguarda 9 segundos antes de repetir a leitura
    }

    return 0;
}

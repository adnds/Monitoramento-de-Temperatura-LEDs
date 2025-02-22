# Monitoramento-de-Temperatura-LEDs
# 📡 Monitoramento de Temperatura com Raspberry Pi Pico W

## 🌍 Visão Geral
Este projeto tem como objetivo monitorar a temperatura e indicar sua faixa por meio de LEDs conectados ao Raspberry Pi Pico W. Cada LED representa uma faixa de temperatura distinta, permitindo uma identificação visual rápida das condições térmicas.

## 🔥❄️ Funcionamento
O sistema simula a leitura de temperatura e aciona LEDs correspondentes:
- 🟢 **LED Verde (17°C a 20°C):** Indica temperatura dentro de um nível considerado seguro.
- 🔵 **LED Azul (21°C a 29°C):** Indica uma temperatura moderada.
- 🔴 **LED Vermelho (30°C a 45°C):** Indica uma temperatura elevada, alertando para condições acima do permitido.

As leituras são simuladas no código e exibidas via UART, permitindo o monitoramento remoto da temperatura.

## 🛠️ Hardware Utilizado
- 💻 BitDogLab
- 🖥️ Raspberry Pi Pico W
- 💡 LED RGB (vermelho, azul e verde)

## ⚙️ Configuração dos Pinos
- **🔴 LED Vermelho:** GP13
- **🔵 LED Azul:** GP12
- **🟢 LED Verde:** GP11
- **📡 UART TX:** GP4
- **📡 UART RX:** GP5

## 🚀 Como Executar
1. ⚙️ Configure o ambiente de desenvolvimento para o Raspberry Pi Pico W com o SDK do Pico.
2. 📝 Compile e carregue o código no Raspberry Pi Pico W.
3. 🔍 Conecte-se à UART para monitorar as leituras de temperatura.

## 🔮 Futuras Melhorias
- 📡 Integração com sensor de temperatura real (como DHT11 ou DS18B20).
- 📶 Envio dos dados para um servidor via Wi-Fi para monitoramento remoto.
- 🔊 Implementação de um sistema de alerta sonoro para temperaturas críticas.


💡 Este projeto é ideal para aprendizado sobre sistemas embarcados, GPIO, UART e monitoramento ambiental usando o Raspberry Pi Pico W.

# Monitor de batimentos cardíacos 

## Uma breve descrição do funcionamento e uso para quem quiser reproduzir.

Trata-se de um projeto que visa o monitoramento de batimentos cardíacos, identificando bradicardia e taquicardia quando ultrapassados os limites considerados normais para uma pessoa em repouso. O funcionamento se dá através da montagem do projeto que será melhor especificado abaixo, e conexão do sensor junto ao pulso para auferir os batimentos. Além da montagem é preciso que o usuário faça download ou clone o presente repositório, faça o cadastro na plataforma AdaFruit IO <https://io.adafruit.com/>, e utilize uma plataforma para execução do código (Arduino IDE). 

O projeto possui comunicação/controle via internet (TCP/IP), através da conexão da placa com o roteador, e uso do Protocolo MQTT via biblioteca Adafruit IO.

O código se encontra nesse repositório, para sua execução é preciso clonar ou fazer o download, abri-lo na Arduino IDE, instalar as bibliotecas "PulseSensor Playground"and "Adafruit BusIO" (visando utilização do protocolo MQTT e conexão com o servidor), criar uma conta em Adafruit IO, criar um feed, com o nome que desejar, e atualizar as seguintes informações no código-fonte:

- Atualizar "username" e "keyAdafruit" baseado nas informações disponibilizadas na plataforma AdaFruit IO (no ícone da chave)

#define IO_USERNAME  "username"
#define IO_KEY       "keyAdafruit"

- Atualizar as informações da conexão que wi-fi que irá utilizar "wifi_username" e informação de senha "wifi_password":

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, "wifi_username", "wifi_password");

## Descrição do hardware utilizado 

- Placa NodeMCU ESP8266 CP2102
- Sensor de batimentos cardíacos XD-58C
- Led difuso vermelho de 5mm
- Resistor CR25 de 270Ω - 1/4W -  +/-5%
- Protoboard de 830 pontos
- Kit jumper macho-macho de 20cm.
- Cabo USB.

## Plataformas de desenvolvimento e servidor:

- Arduino IDE
- Adafruit IO

# Heartbeat Monitor

## First step

- Download or clone repository.
- Open it on Arduino IDE.
- Install libraries "PulseSensor Playground"and "Adafruit BusIO" (for MQTT protocol connection).

## Update Code:

- Update "username" and "keyAdafruit" information based on the username and keys provided by AdaFruit IO. (Sign up: https://io.adafruit.com/):

#define IO_USERNAME  "username"
#define IO_KEY       "keyAdafruit"

- Update the wifi username "wifi_username" and password information "wifi_password":

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, "wifi_username", "wifi_password");

## Components

- NodeMCU board ESP8266 CP2102.
- XD-58C heart rate sensor.
- Diffuse red 5mm LED.
- 270Ω CR25 resistor- 1/4W - +/-5%.
- 830-point breadboard.
- 20cm male-male jumper kit.
- USB cable.

## Circuit design

![hardware design](https://user-images.githubusercontent.com/72820242/202512285-61477cc2-53e2-4ff1-bcdd-bb70cb744e9e.png)

## Hardware

![hardware](https://user-images.githubusercontent.com/72820242/202513721-fb2cfa0e-e2fd-411e-b28c-42cb35f316cc.png)

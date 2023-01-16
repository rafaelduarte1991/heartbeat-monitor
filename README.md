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


#define USE_ARDUINO_INTERRUPTS false 
#define IO_USERNAME  "username"
#define IO_KEY       "keyAdafruit"
#include <PulseSensorPlayground.h>
#include <AdafruitIO_WiFi.h>

const int OUTPUT_TYPE = PROCESSING_VISUALIZER;

const int PULSE_INPUT = A0;
const int PULSE_BLINK = 13;    
const int PULSE_FADE = 5;
const int THRESHOLD = 550;   

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, "wifi_username", "wifi_password");
AdafruitIO_Feed *feedbpm = io.feed("bpm");
byte samplesUntilReport;
const byte SAMPLES_PER_SERIAL_SAMPLE = 10;

float contador = 0;

PulseSensorPlayground pulseSensor;

void setup() {
  
  Serial.begin(115200);
  
  pinMode(D0, OUTPUT);

  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.blinkOnPulse(PULSE_BLINK);
  pulseSensor.fadeOnPulse(PULSE_FADE);
  pulseSensor.setSerial(Serial);
  pulseSensor.setOutputType(OUTPUT_TYPE);
  pulseSensor.setThreshold(THRESHOLD);

  samplesUntilReport = SAMPLES_PER_SERIAL_SAMPLE;

  Serial.println("Testando conexão");
  io.connect(); 
  while (io.status() < AIO_CONNECTED) {
    Serial.print('.');
    delay(500);
  }

  
  if (!pulseSensor.begin()) {
    
    for (;;) {
      digitalWrite(PULSE_BLINK, LOW);
      delay(50);
      digitalWrite(PULSE_BLINK, HIGH);
      delay(50);
    }
  }
}

void loop() {

  if (pulseSensor.sawNewSample()) {
    io.run(); 
    if (--samplesUntilReport == (byte) 0) {
      samplesUntilReport = SAMPLES_PER_SERIAL_SAMPLE;
      pulseSensor.outputSample();
      
      if (pulseSensor.sawStartOfBeat()) {
        pulseSensor.outputBeat();
      }
    }
    
    if (contador > 50) {
      contador = 0;
      Serial.println("Enviando para servidor");
      int bpm = pulseSensor.getBeatsPerMinute();
      feedbpm->save(bpm);
      if (bpm > 90 || bpm < 50) {
        digitalWrite(D0, HIGH);
      } 
      else {
        digitalWrite(D0, LOW);
      } 
    }
    contador++;
  }
}

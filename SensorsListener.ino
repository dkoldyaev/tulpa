#include "LightSensor.h"
#include "TemperatureSensor.h"

#define NUM_SENSORS 2

Sensor* sensors[NUM_SENSORS];
int sensorPins[NUM_SENSORS] = {A5, A7};  // Пины для датчиков

void setup() {
  Serial.begin(9600);

  // Инициализация датчиков
  sensors[0] = new LightSensor();
  sensors[1] = new TemperatureSensor();

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensors[i]->initialize(sensorPins[i]);
  }
}

void loop() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensors[i]->getName());
    Serial.print(": ");
    Serial.println(sensors[i]->readValue());
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(1000); // Задержка 1 секунда перед следующим чтением
}

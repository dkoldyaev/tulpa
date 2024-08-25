#include "LightSensor.h"
#include "TemperatureSensor.h"

#define NUM_SENSORS 2

bool debugMode = true;  // Флаг отладки
int minResultValue = 0;
int maxResultValue = 255;

Sensor* sensors[NUM_SENSORS];

void setup() {
  Serial.begin(9600);

  // Инициализация датчиков через конструкторы
  sensors[0] = new LightSensor(A5, 0, 255);
  sensors[1] = new TemperatureSensor(A7, -40, 125);
}

void loop() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensors[i]->getName());
    Serial.print(": ");
    Serial.println(debugMode ? sensors[i]->readValue(0, 255) : sensors[i]->rawValue());
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(1000); // Задержка 1 секунда перед следующим чтением
}

#include "LightSensor.h"
#include "TemperatureSensor.h"
#include "SensorNode.h"

bool debugMode = true;  // Флаг отладки

SensorNode* head = nullptr;  // Указатель на голову списка

void addSensor(Sensor* sensor) {
    SensorNode* newNode = new SensorNode(sensor);
    if (head == nullptr) {
        head = newNode;
    } else {
        SensorNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void setup() {
  Serial.begin(9600);

  // Добавляем датчики в связный список
  addSensor(new LightSensor(A5, 0, 255));
  addSensor(new TemperatureSensor(A7, -40, 125));
}

void loop() {
  SensorNode* current = head;
  while (current != nullptr) {
    Sensor* sensor = current->sensor;
    Serial.print(sensor->getName());
    Serial.print(": ");
    Serial.println(debugMode ? sensor->rawValue() : sensor->readValue(0, 255));
    current = current->next;
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(1000); // Задержка 1 секунда перед следующим чтением
}

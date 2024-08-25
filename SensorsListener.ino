#include "LightSensor.h"
#include "TemperatureSensor.h"
#include "SensorNode.h"
#include "Phrases.h"
#define BUFFER_SIZE 50

bool debugMode = false;  // Флаг отладки
int outerValue = 50;

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
  addSensor(new TemperatureSensor(A7, 0, 2));
}

void loop() {
  SensorNode* current = head;
  int sensorIndex = 0;
  char buffer[BUFFER_SIZE];

  while (current != nullptr) {
    Sensor* sensor = current->sensor;
    if (debugMode) {
      Serial.print(sensor->getName());
      Serial.print(" Out: ");
      Serial.print(sensor->readValue(0, outerValue));
      Serial.print(" Raw: ");
      Serial.print(sensor->rawValue());
      Serial.println();
    }

    // Извлечение и вывод фразы из PROGMEM
    strcpy_P(buffer, (char*)pgm_read_word(&(phrases[sensorIndex][sensor->readValue(0, outerValue) % 4])));
    Serial.print(buffer);
    Serial.print(" ");
    
    Serial.println();
    current = current->next;
    sensorIndex++;
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(5000); // Задержка 1 секунда перед следующим чтением
}

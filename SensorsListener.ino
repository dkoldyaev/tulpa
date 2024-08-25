#include "LightSensor.h"
#include "TemperatureSensor.h"
#include "ShockSensor.h"
#include "SoilMoistureSensor.h"
#include "Phrases.h"
#include "SensorNode.h"

bool debugMode = false;  // Флаг отладки
int minResultValue = 0;
int maxResultValue = 39;
SensorNode* head = nullptr;
char fullPhrase[400] = "";

void removeLastNewline(char* str) {
  int len = strlen(str);
  
  // Проверяем последний символ строки и удаляем перенос строки, если он присутствует
  if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
    str[len - 1] = '\0';
  }
}

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

  // Инициализация датчиков и добавление их в список
  addSensor(new LightSensor(A5, 0, 255));
  addSensor(new TemperatureSensor(A7, -40, 125));
  addSensor(new ShockSensor(2, 0, 1));  // Подключаем датчик шока на пин 2 (цифровой)
  addSensor(new SoilMoistureSensor(A6, 0, 1023));  // Подключаем датчик влажности почвы на A6
}

void loop() {
  SensorNode* current = head;
  int sensorIndex = 0;
  char buffer[100]; // Буфер для хранения строки из PROGMEM

  while (current != nullptr) {
    fullPhrase[0] = '\0';
    Sensor* sensor = current->sensor;
    if (debugMode) {
      Serial.println(sensor->getName());
      Serial.print("Out: ");
      Serial.println(sensor->readValue(0, maxResultValue));
      Serial.print("Raw: ");
      Serial.println(sensor->rawValue());
    }
    
    // Извлечение фразы из PROGMEM и добавление к полной строке
    strcpy_P(buffer, (char*)pgm_read_word(&(phrases[sensorIndex][sensor->readValue(0, maxResultValue) % 4])));
    
    removeLastNewline(buffer); // Удаляем последний символ переноса строки
    strcat(fullPhrase, buffer); // Склеиваем фразу
    strcat(fullPhrase, " ");    // Добавляем пробел между словами

    Serial.println(fullPhrase);

    current = current->next;
    sensorIndex++;
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(5000); // Задержка 1 секунда перед следующим чтением
}

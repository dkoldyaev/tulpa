#include "DHT11HumiditySensor.h"
#include "DHT11TemperatureSensor.h"
#include "LightAnalogSensor.h"
#include "LightDigitalSensor.h"
#include "MQ2AirQualitySensor.h"
#include "TemperatureSensor.h"
#include "ShockSensor.h"
#include "SoilMoistureSensor.h"
#include "WaterLevelSensor.h"

#include "Phrases.h"
#include "SensorNode.h"

bool debugMode = true;  // Флаг отладки
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
    addSensor(new DHT11TemperatureSensor(A6));                // Датчик температуры (DHT11) A6
    addSensor(new DHT11HumiditySensor(A6));                   // Датчик влажности (DHT11) A6

    addSensor(new LightDigitalSensor(D5, 0, 100));              // Освещение (DO) D5
    addSensor(new LightAnalogSensor(A5, 0, 10));               // Освещение (DO) D5

    addSensor(new SoilMoistureSensor(D7, 0, 1023));           // Датчик влажности почвы D7
    addSensor(new WaterLevelSensor(A4, 0, 1023));             // Уровень воды A4
              
    addSensor(new TemperatureSensor(D6, -40, 125));           // Температура 1 D6
    addSensor(new TemperatureSensor(D2, -40, 125));           // Температура 2 D2
    
    addSensor(new ShockSensor(D4, 0, 1));                     // Shock 1 D4
    addSensor(new ShockSensor(D3, 0, 1));                     // Shock 2 D3
    
    addSensor(new MQ2AirQualitySensor(A7, 0, 1023));                    // MQ-2 A7
}

void loop() {
  SensorNode* current = head;
  int sensorIndex = 0;
  char buffer[100]; // Буфер для хранения строки из PROGMEM
  char debugString[1000];       // Строка для дебаг-данных
  bool shockDetected = false;  // Флаг для обнаружения срабатывания датчика шока

  // Моргаем встроенным светодиодом
  digitalWrite(LED_BUILTIN, HIGH);   // Включаем светодиод
  delay(100);                        // Держим светодиод включенным 100 мс
  digitalWrite(LED_BUILTIN, LOW);    // Выключаем светодиод
  delay(100);  

  while (current != nullptr) {
    fullPhrase[0] = '\0';
    Sensor* sensor = current->sensor;
    if (debugMode) {
      sprintf(buffer, "%s; Raw: %d; Out: %d", sensor->getName(), sensor->rawValue(), sensor->readValue(0, maxResultValue));
      Serial.println(buffer);
    }

    // Проверка срабатывания датчика шока
    if (strcmp(sensor->getName(), "Shock Sensor") == 0 && sensor->rawValue() == 1) {
        shockDetected = true;
    }
    
    // Если датчик шока сработал, моргаем светодиодом
    if (shockDetected) {
        digitalWrite(LED_BUILTIN, HIGH);   // Включаем светодиод
        delay(100);                        // Держим светодиод включенным 100 мс
        digitalWrite(LED_BUILTIN, LOW);    // Выключаем светодиод
        delay(100);                        // Держим светодиод выключенным 100 мс
    }
    
    // // Извлечение фразы из PROGMEM и добавление к полной строке
    // strcpy_P(buffer, (char*)pgm_read_word(&(phrases[sensorIndex][sensor->readValue(0, maxResultValue) % 4])));
    
    // removeLastNewline(buffer); // Удаляем последний символ переноса строки
    // strcat(fullPhrase, buffer); // Склеиваем фразу
    // strcat(fullPhrase, " ");    // Добавляем пробел между словами

    // Serial.println(fullPhrase);

    current = current->next;
    sensorIndex++;
  }
  Serial.println(); // Пустая строка для разделения данных

  delay(5000); // Задержка 1 секунда перед следующим чтением
}

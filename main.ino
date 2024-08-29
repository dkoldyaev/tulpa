#include "DHT11HumiditySensor.h"
#include "DHT11TemperatureSensor.h"
#include "LightAnalogSensor.h"
#include "LightDigitalSensor.h"
#include "MQ2AirQualitySensor.h"
#include "TemperatureSensor.h"
#include "ShockSensor.h"
#include "SoilMoistureSensor.h"
#include "WaterLevelSensor.h"
#include "AudioSensor.h"

#include "Phrases.h"
#include "SensorNode.h"

bool debugMode = true;  // Флаг отладки
int minResultValue = 0;
int maxResultValue = 39;
SensorNode* head = nullptr;
char fullPhrase[400] = "";
unsigned long lastPrintTime = 0;  // Время последнего вывода данных
unsigned long printInterval = 5000;  // Интервал между выводами данных в миллисекундах

void removeLastNewline(char* str) {
    int len = strlen(str);
    // Проверяем последний символ строки и удаляем перенос строки, если он присутствует
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
    }
}

void addSensor(Sensor* sensor) {
    SensorNode* newNode = new SensorNode(sensor);
    newNode->totalMinValue = 1000;
    newNode->totalMaxValue = -1000;
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
    pinMode(LED_BUILTIN, OUTPUT); // Инициализация встроенного светодиода

    // Инициализация датчиков и добавление их в список
    // addSensor(new DHT11TemperatureSensor(A6));                
    // addSensor(new DHT11HumiditySensor(A6));      
    DHT11HumiditySensor* humSensor = new DHT11HumiditySensor(A6); // Датчик влажности (DHT11) A6
    // humSensor->begin();
    addSensor(humSensor);
                 
    DHT11TemperatureSensor* tempSensor = new DHT11TemperatureSensor(A6); // Датчик температуры (DHT11) A6
    tempSensor->begin();
    addSensor(tempSensor);

    addSensor(new LightDigitalSensor(D5, 0, 1));              // Освещение (DO) D5
    addSensor(new LightAnalogSensor(A5, 0, 15));               // Освещение (DO) D5

    addSensor(new SoilMoistureSensor(D7, 0, 1023));           // Датчик влажности почвы D7
    addSensor(new WaterLevelSensor(A4, 0, 1023));             // Уровень воды A4
              
    addSensor(new TemperatureSensor(D6, -40, 125));           // Температура 1 D6
    addSensor(new TemperatureSensor(D2, -40, 125));           // Температура 2 D2
    
    addSensor(new ShockSensor(D4, 8, 12));                     // Shock 1 D4
    addSensor(new AudioSensor(D3, 0, 255));                     // Shock 2 D3
    
    addSensor(new MQ2AirQualitySensor(A7, 0, 1023));          // MQ-2 A7
}

void loop() {
    unsigned long currentTime = millis();
    SensorNode* current = head;
    int sensorIndex = 0;
    char buffer[100];            // Буфер для хранения строки из PROGMEM
    int shockDetected = 0;  // Флаг для обнаружения срабатывания датчика шока

    while (current != nullptr) {
        Sensor* sensor = current->sensor;
        int currentValue = sensor->rawValue();
        if (current->totalMinValue > currentValue) {
          current->totalMinValue = currentValue;
        }
        if (current->totalMaxValue < currentValue) {
          current->totalMaxValue = currentValue;
        }
        shockDetected = 0;

        // Проверка срабатывания датчика шока
        if (strcmp(sensor->getName(), "Audio Sensor") == 0) {
            // shockDetected = sensor->rawValue();
            Serial.println(sensor->rawValue());
        }

        current = current->next;
        sensorIndex++;
    }

    // Если датчик шока сработал, моргаем светодиодом
    // if (shockDetected != 0) {
    //     digitalWrite(LED_BUILTIN, HIGH);   // Включаем светодиод
    //     delay(50);                        // Держим светодиод включенным 100 мс
    //     digitalWrite(LED_BUILTIN, LOW);    // Выключаем светодиод
    //     delay(50);                        // Держим светодиод выключенным 100 мс
    //     digitalWrite(LED_BUILTIN, HIGH);   // Включаем светодиод
    //     delay(50);                        // Держим светодиод включенным 100 мс
    //     digitalWrite(LED_BUILTIN, LOW);    // Выключаем светодиод
    //     delay(50);                        // Держим светодиод выключенным 100 мс
    //     digitalWrite(LED_BUILTIN, HIGH);   // Включаем светодиод
    //     delay(50);                        // Держим светодиод включенным 100 мс
    //     digitalWrite(LED_BUILTIN, LOW);    // Выключаем светодиод
    //     delay(50);                        // Держим светодиод выключенным 100 мс
    // }

    // Вывод данных раз в 5 секунд
    if (currentTime - lastPrintTime >= printInterval) {
        lastPrintTime = currentTime;  // Обновляем время последнего вывода
        current = head;
        sensorIndex = 0;

        while (current != nullptr) {
            Sensor* sensor = current->sensor;
            sprintf(
              buffer,
              "%s\tRaw: %d;\tOut: %d\tMin:%d\tMax:%d",
              sensor->getName(),
              sensor->rawValue(),
              sensor->readValue(0, maxResultValue),
              current->totalMinValue,
              current->totalMaxValue
            );
            Serial.println(buffer);

            current = current->next;
            sensorIndex++;
        }

        Serial.println(); // Пустая строка для разделения данных
    }
}

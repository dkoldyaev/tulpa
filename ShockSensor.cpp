#include "ShockSensor.h"

ShockSensor::ShockSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int ShockSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = digitalRead(pin);  // Цифровое чтение для датчика шока
    if (debugMode) {
        return rawValue;  // Возвращаем сырые данные
    }
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int ShockSensor::rawValue() {
  return digitalRead(pin);  // Цифровое чтение для датчика шока
}

const char* ShockSensor::getName() {
    return "Shock Sensor";
}

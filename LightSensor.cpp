#include "LightSensor.h"

LightSensor::LightSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int LightSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    if (debugMode) {
        return rawValue;  // Возвращаем сырые данные
    }
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int LightSensor::rawValue() {
  return analogRead(pin);
}

const char* LightSensor::getName() {
    return "Light Sensor";
}

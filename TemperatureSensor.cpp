#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int TemperatureSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int TemperatureSensor::rawValue() {
  return analogRead(pin);
}

const char* TemperatureSensor::getName() {
    return "Temperature Sensor\t";
}

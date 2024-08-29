#include "ShockSensor.h"

ShockSensor::ShockSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int ShockSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin); 
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int ShockSensor::rawValue() {
  return analogRead(pin);
}

const char* ShockSensor::getName() {
    return "Shock Sensor";
}

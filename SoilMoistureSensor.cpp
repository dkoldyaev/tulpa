#include "SoilMoistureSensor.h"

SoilMoistureSensor::SoilMoistureSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int SoilMoistureSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    return map(rawValue, minValue, maxResultValue, minResultValue, maxResultValue);
}

int SoilMoistureSensor::rawValue() {
  return analogRead(pin);
}

const char* SoilMoistureSensor::getName() {
    return "Soil Moisture Sensor\t";
}

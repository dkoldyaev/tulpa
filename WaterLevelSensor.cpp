#include "WaterLevelSensor.h"

WaterLevelSensor::WaterLevelSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int WaterLevelSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    return map(rawValue, minValue, maxResultValue, minResultValue, maxResultValue);
}

int WaterLevelSensor::rawValue() {
  return analogRead(pin);
}

const char* WaterLevelSensor::getName() {
    return "Water Level Sensor";
}

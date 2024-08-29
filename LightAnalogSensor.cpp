#include "LightAnalogSensor.h"

LightAnalogSensor::LightAnalogSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int LightAnalogSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int LightAnalogSensor::rawValue() {
  return analogRead(pin);
}

const char* LightAnalogSensor::getName() {
    return "Light Analog Sensor\t";
}

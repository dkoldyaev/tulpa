#include "LightDigitalSensor.h"

LightDigitalSensor::LightDigitalSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int LightDigitalSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = digitalRead(pin); // Digital read for DO pin
    return map(rawValue, minValue, maxResultValue, minResultValue, maxResultValue);
}

int LightDigitalSensor::rawValue() {
    return digitalRead(pin);
}

const char* LightDigitalSensor::getName() {
    return "Light Digital Sensor";
}

#include "LightDigitalSensor.h"

LightDigitalSensor::LightDigitalSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int LightDigitalSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin); // Digital read for DO pin
    return map(rawValue, minValue, maxResultValue, minResultValue, maxResultValue);
}

int LightDigitalSensor::rawValue() {
    return analogRead(pin);
}

const char* LightDigitalSensor::getName() {
    return "Light Digital Sensor\t";
}

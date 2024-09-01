#include "MQ2AirQualitySensor.h"

MQ2AirQualitySensor::MQ2AirQualitySensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int MQ2AirQualitySensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin);
    return map(rawValue, minValue, maxResultValue, minResultValue, maxResultValue);
}

int MQ2AirQualitySensor::rawValue() {
    return analogRead(pin);
}

const char* MQ2AirQualitySensor::getName() {
    return "MQ-2 Air Quality Sensor";
}

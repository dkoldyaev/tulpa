#include "AudioSensor.h"

AudioSensor::AudioSensor(int pin, int minValue, int maxValue) {
    this->pin = pin;
    this->minValue = minValue;
    this->maxValue = maxValue;
    pinMode(pin, INPUT);
}

int AudioSensor::readValue(int minResultValue, int maxResultValue) {
    int rawValue = analogRead(pin); 
    return map(rawValue, minValue, maxValue, minResultValue, maxResultValue);
}

int AudioSensor::rawValue() {
  return analogRead(pin);
}

const char* AudioSensor::getName() {
    return "Audio Sensor";
}

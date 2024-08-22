#include "LightSensor.h"

void LightSensor::initialize(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

int LightSensor::readValue() {
    int rawValue = analogRead(pin);
    return map(rawValue, 0, 1023, 0, 255);
}

const char* LightSensor::getName() {
    return "Light Sensor";
}

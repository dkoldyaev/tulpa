#include "TemperatureSensor.h"

void TemperatureSensor::initialize(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

int TemperatureSensor::readValue() {
    int rawValue = analogRead(pin);
    return map(rawValue, 0, 1023, 0, 255);
}

const char* TemperatureSensor::getName() {
    return "Temperature Sensor";
}

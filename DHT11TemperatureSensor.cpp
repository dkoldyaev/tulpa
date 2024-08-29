#include "DHT11TemperatureSensor.h"

DHT11TemperatureSensor::DHT11TemperatureSensor(int pin) : dht(pin, DHT11) {
    this->pin = pin;
    dht.begin();
}

int DHT11TemperatureSensor::readValue(int minResultValue, int maxResultValue) {
    temperature = dht.readTemperature();
    return map((int)temperature, 0, 50, minResultValue, maxResultValue);
}

int DHT11TemperatureSensor::rawValue() {
    return (int)dht.readTemperature();
}

const char* DHT11TemperatureSensor::getName() {
    return "DHT11 Temperature Sensor";
}

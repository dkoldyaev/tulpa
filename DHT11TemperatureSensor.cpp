#include "DHT11TemperatureSensor.h"

DHT11TemperatureSensor::DHT11TemperatureSensor(DHT11Sensor* sensor) {
    this->sensor = sensor;
}

int DHT11TemperatureSensor::readValue(int minResultValue, int maxResultValue) {
    return map(rawValue(), 0, 50, minResultValue, maxResultValue);
}

int DHT11TemperatureSensor::rawValue() {
    return this->sensor->readTemperatureRaw();
}

const char* DHT11TemperatureSensor::getName() {
    return "DHT11 Temperature Sensor";
}

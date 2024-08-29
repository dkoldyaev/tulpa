#include "DHT11Sensor.h"

DHT11Sensor::DHT11Sensor(int pin) : dht(pin, DHT11) {
    this->pin = pin;
}

void DHT11Sensor::begin() {
    dht.begin();
}

int DHT11Sensor::readHumidityRaw() {
    return (int)dht.readHumidity();
}

int DHT11Sensor::readTemperatureRaw() {
    return (int)dht.readTemperature();
}

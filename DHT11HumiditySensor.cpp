#include "DHT11HumiditySensor.h"

DHT11HumiditySensor::DHT11HumiditySensor(int pin) : dht(pin, DHT11) {
    this->pin = pin;
    // dht.begin();
}

void DHT11HumiditySensor::begin() {
    dht.begin();  // Инициализация DHT11 сенсора
}

int DHT11HumiditySensor::readValue(int minResultValue, int maxResultValue) {
    humidity = dht.readHumidity();
    return map((int)humidity, 0, 100, minResultValue, maxResultValue);
}

int DHT11HumiditySensor::rawValue() {
    return (int)dht.readHumidity();
}

const char* DHT11HumiditySensor::getName() {
    return "DHT11 Humidity Sensor\t";
}

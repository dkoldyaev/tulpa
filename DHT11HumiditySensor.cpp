#include "DHT11HumiditySensor.h"

DHT11HumiditySensor::DHT11HumiditySensor(DHT11Sensor* sensor) {
    this->sensor = sensor;
}

int DHT11HumiditySensor::readValue(int minResultValue, int maxResultValue) {
    return map(rawValue(), 0, 100, minResultValue, maxResultValue);
}

int DHT11HumiditySensor::rawValue() {
    return this->sensor->readHumidityRaw();
}

const char* DHT11HumiditySensor::getName() {
    return "DHT11 Humidity Sensor";
}

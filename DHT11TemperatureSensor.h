#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include "Sensor.h"
#include <DHT.h>

class DHT11TemperatureSensor : public Sensor {
public:
    DHT11TemperatureSensor(int pin);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;

private:
    DHT dht;
    float temperature;
};

#endif

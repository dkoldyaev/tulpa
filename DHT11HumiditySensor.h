#ifndef DHT11_HUMIDITY_SENSOR_H
#define DHT11_HUMIDITY_SENSOR_H

#include "Sensor.h"
#include <DHT.h>

class DHT11HumiditySensor : public Sensor {
public:
    DHT11HumiditySensor(int pin);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;

private:
    DHT dht;
    float humidity;
};

#endif

#ifndef DHT11_HUMIDITY_SENSOR_H
#define DHT11_HUMIDITY_SENSOR_H

#include "Sensor.h"
#include "DHT11Sensor.h"

class DHT11HumiditySensor : public Sensor {
public:
    DHT11HumiditySensor(DHT11Sensor* sensor);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;

private:
    DHT11Sensor* sensor;
};

#endif

#ifndef DHT11_TEMPERATURE_SENSOR_H
#define DHT11_TEMPERATURE_SENSOR_H

#include "Sensor.h"
#include "DHT11Sensor.h"

class DHT11TemperatureSensor : public Sensor {
public:
    DHT11TemperatureSensor(DHT11Sensor* sensor);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;

private:
    DHT11Sensor* sensor;
};

#endif

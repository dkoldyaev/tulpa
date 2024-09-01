#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

#include <DHT.h>

class DHT11Sensor {
public:
    DHT11Sensor(int pin);
    void begin();
    int readHumidityRaw();
    int readTemperatureRaw();

private:
    DHT dht;
    int pin;
};

#endif

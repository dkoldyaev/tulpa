#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

extern bool debugMode;  // Флаг для режима отладки

class Sensor {
protected:
    int pin;
    int minValue;
    int maxValue;

public:
    virtual int readValue(int minResultValue, int maxResultValue) = 0;
    virtual int rawValue() = 0;
    virtual const char* getName() = 0;
};

#endif

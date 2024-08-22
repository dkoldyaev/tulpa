#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
public:
    virtual void initialize(int pin) = 0;
    virtual int readValue() = 0;
    virtual const char* getName() = 0;
};

#endif

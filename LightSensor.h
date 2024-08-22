#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "Sensor.h"

class LightSensor : public Sensor {
private:
    int pin;

public:
    void initialize(int pin) override;
    int readValue() override;
    const char* getName() override;
};

#endif

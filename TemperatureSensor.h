#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor {
private:
    int pin;

public:
    void initialize(int pin) override;
    int readValue() override;
    const char* getName() override;
};

#endif

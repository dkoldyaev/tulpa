#ifndef SHOCK_SENSOR_H
#define SHOCK_SENSOR_H

#include "Sensor.h"

class ShockSensor : public Sensor {
public:
    ShockSensor(int pin, int minValue, int maxValue);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;
};

#endif

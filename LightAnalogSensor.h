#ifndef LIGHT_ANALOG_SENSOR_H
#define LIGHT_ANALOG_SENSOR_H

#include "Sensor.h"

class LightAnalogSensor : public Sensor {
public:
    LightAnalogSensor(int pin, int minValue, int maxValue);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;
};

#endif

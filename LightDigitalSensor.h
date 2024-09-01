#ifndef LIGHT_DIGITAL_SENSOR_H
#define LIGHT_DIGITAL_SENSOR_H

#include "Sensor.h"

class LightDigitalSensor : public Sensor {
public:
    LightDigitalSensor(int pin, int minValue, int maxValue);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;
};

#endif

#ifndef AUDIO_SENSOR_H
#define AUDIO_SENSOR_H

#include "Sensor.h"

class ShockSensor : public Sensor {
public:
    ShockSensor(int pin, int minValue, int maxValue);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;
};

#endif

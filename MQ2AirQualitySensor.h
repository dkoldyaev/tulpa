#ifndef MQ2_SENSOR_H
#define MQ2_SENSOR_H

#include "Sensor.h"

class MQ2AirQualitySensor : public Sensor {
public:
    MQ2AirQualitySensor(int pin, int minValue, int maxValue);
    int readValue(int minResultValue, int maxResultValue) override;
    int rawValue() override;
    const char* getName() override;
};

#endif

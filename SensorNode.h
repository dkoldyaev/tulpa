#ifndef SENSOR_NODE_H
#define SENSOR_NODE_H

#include "Sensor.h"

struct SensorNode {
    Sensor* sensor;
    SensorNode* next;
    public: int totalMinValue;
    public: int totalMaxValue;

    SensorNode(Sensor* sensor) : sensor(sensor), next(nullptr) {}
};

#endif

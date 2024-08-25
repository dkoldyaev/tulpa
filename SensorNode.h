#ifndef SENSOR_NODE_H
#define SENSOR_NODE_H

#include "Sensor.h"

struct SensorNode {
    Sensor* sensor;
    SensorNode* next;

    SensorNode(Sensor* sensor) : sensor(sensor), next(nullptr) {}
};

#endif

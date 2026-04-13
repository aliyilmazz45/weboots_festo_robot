/**
 * @file SensorInterface.h
 * @brief Abstract interface for sensors.
 *
 * This file defines the SensorInterface class, which serves as an abstract
 * base class for different types of sensors. It provides a standardized
 * interface for retrieving sensor data and properties.
 */

#pragma once
#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

using namespace std;

/**
 * @class SensorInterface
 * @brief Abstract interface for sensors.
 *
 * The SensorInterface class provides a set of pure virtual methods that
 * must be implemented by all sensor types. These methods handle updating
 * sensor data and retrieving sensor properties like range, type, and angle.
 */
class SensorInterface {
public:
    /**
     * @brief Updates the sensor data.
     *
     * This method should be called to refresh the sensor's internal data.
     */
    virtual void update() = 0;

    /**
     * @brief Retrieves the type of the sensor.
     * @return A string representing the sensor type.
     */
    virtual string getSensorType() const = 0;

    /**
     * @brief Retrieves the value of a specific sensor.
     * @param index The index of the sensor.
     * @return The value of the sensor at the specified index.
     */
    virtual double getSensorValue(int index) const = 0;

    /**
     * @brief Retrieves the range (distance) value of a specific sensor.
     * @param index The index of the sensor.
     * @return The range value in meters.
     */
    virtual double getRange(int index) const = 0;

    /**
     * @brief Retrieves the total number of ranges supported by the sensor.
     * @return The number of ranges.
     */
    virtual int getRangeNumber() const = 0;

    /**
     * @brief Retrieves the angle for a specific sensor index.
     * @param index The index of the sensor.
     * @return The angle in degrees corresponding to the sensor index.
     */
    virtual double getAngle(int index) const = 0;

    /**
     * @brief Virtual destructor for SensorInterface.
     */
    virtual ~SensorInterface() = default;
};

#endif // SENSORINTERFACE_H

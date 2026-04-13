// Murat Küçük 22.12.2024
// 152120221117
/**
 * @file IRSensor.h
 * @brief Header file for the IRSensor class.
 *
 * This file defines the IRSensor class, which manages IR sensor data from the robot.
 */

#pragma once
#ifndef IRSENSOR_H
#define IRSENSOR_H

#include "FestoRobotSensorInterface.h"

 /**
  * @class IRSensor
  * @brief Handles IR sensor data collection and retrieval.
  */
class IRSensor : public FestoRobotSensorInterface {
private:
    double ranges[9]; /**< Stores distance values for the 9 IR sensors. */

public:
    /**
     * @brief Constructor for the IRSensor class.
     * @param api Pointer to the robot's FestoRobotAPI.
     */
    IRSensor(FestoRobotAPI* api);

    /**
     * @brief Retrieves the sensor value for a given index.
     * @param index The sensor index.
     * @return The sensor value (implementation-specific).
     */
    double getSensorValue(int index) const;

    /**
     * @brief Retrieves the type of the sensor.
     * @return A string representing the sensor type.
     */
    string getSensorType() const;

    /**
     * @brief Retrieves the number of ranges supported by the sensor.
     * @return The number of ranges (implementation-specific).
     */
    int getRangeNumber() const;

    /**
     * @brief Retrieves the angle of a specific sensor.
     * @param index The sensor index.
     * @return The angle in degrees (implementation-specific).
     */
    double getAngle(int index) const;

    /**
     * @brief Updates sensor data from the robot.
     */
    void update();

    /**
     * @brief Retrieves the range value from a specific sensor.
     * @param index The index of the sensor (0-8).
     * @return The distance measured by the sensor in meters.
     * @throws std::out_of_range If the index is outside the valid range (0-8).
     */
    double getRange(int index) const;

    /**
     * @brief Overloaded subscript operator for accessing sensor values.
     * @param index The index of the sensor (0-8).
     * @return The distance measured by the sensor in meters.
     */
    double operator[](int index) const;
};

#endif // IRSENSOR_H

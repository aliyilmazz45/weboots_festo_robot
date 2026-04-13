/**
 * @file LidarSensor.h
 * @brief Header file for the LidarSensor class.
 *
 * This file defines the LidarSensor class, which manages lidar data from the robot,
 * including range updates, minimum and maximum distances, and angles.
 */

#pragma once
#include "FestoRobotSensorInterface.h"
#include <vector>
#include <iostream>
#include <algorithm>

 /**
  * @class LidarSensor
  * @brief Manages lidar data and provides range and angle information.
  *
  * The LidarSensor class interacts with the robot's API to fetch and process lidar
  * range data. It includes functionalities for retrieving ranges, calculating angles,
  * and determining the minimum and maximum distances.
  */
class LidarSensor : public FestoRobotSensorInterface {
private:
    std::vector<double> ranges; /**< Stores lidar range data. */

public:
    /**
     * @brief Constructs a LidarSensor object.
     * @param robotAPI Pointer to the robot's API for accessing lidar data.
     * @throws std::invalid_argument If the provided robotAPI pointer is null.
     */
    explicit LidarSensor(FestoRobotAPI* robotAPI);

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
     * @brief Updates the lidar range data by fetching values from the robot API.
     */
    void update() override;

    /**
     * @brief Returns the number of lidar ranges available.
     * @return The fixed number of lidar ranges.
     */
    int getRangeNumber() const;

    /**
     * @brief Returns the range (distance) value at a specific index.
     * @param index The index of the range (0-166).
     * @return The range value in meters.
     * @throws std::out_of_range If the index is out of the valid range.
     */
    double getRange(int index) const;

    /**
     * @brief Finds the maximum range value and its index.
     * @param index Reference to store the index of the maximum range.
     * @return The maximum range value in meters.
     */
    double getMax(int& index) const;

    /**
     * @brief Finds the minimum range value and its index.
     * @param index Reference to store the index of the minimum range.
     * @return The minimum range value in meters.
     */
    double getMin(int& index) const;

    /**
     * @brief Prints all lidar range values to the console.
     */
    void printRanges() const;

    /**
     * @brief Overloaded subscript operator to access lidar range values.
     * @param index The index of the range (0-166).
     * @return The range value in meters.
     * @throws std::out_of_range If the index is out of the valid range.
     */
    double operator[](int index) const;

    /**
     * @brief Returns the angle for a specific lidar sensor index.
     * @param index The index of the lidar sensor (0-166).
     * @return The angle in degrees corresponding to the sensor index.
     * @throws std::out_of_range If the index is out of the valid range.
     */
    double getAngle(int index) const;
};

/**
 * @file LidarSensor.cpp
 * @brief Implementation of the LidarSensor class for managing lidar sensor data.
 */

#include "LidarSensor.h"
#include <stdexcept>

 /**
  * @brief Constructs a LidarSensor object.
  * @param robotAPI Pointer to the robot's API for accessing lidar data.
  * @throws std::invalid_argument If the provided robotAPI pointer is null.
  */
LidarSensor::LidarSensor(FestoRobotAPI* robotAPI) : FestoRobotSensorInterface(robotAPI) {
    if (!robotAPI) {
        throw std::invalid_argument("robotAPI pointer cannot be null");
    }
    ranges.resize(167, 0.0); // Initialize storage for 167 sensor data points
}

/**
 * @brief Retrieves the sensor value for a given index.
 * @param index The sensor index.
 * @return The sensor value (currently returns the index for testing).
 */
double LidarSensor::getSensorValue(int index) const {
    return index;
}

/**
 * @brief Retrieves the type of the sensor.
 * @return A string representing the sensor type.
 */
string LidarSensor::getSensorType() const {
    return "Lidar Sensor";
}

/**
 * @brief Updates the lidar sensor data by fetching the latest ranges from the robot API.
 */
void LidarSensor::update() {
    int rangeNumber = robotAPI->getLidarRangeNumber(); // Get the number of available data points
    if (rangeNumber <= 0) {
        std::cerr << "Error: No Lidar data available." << std::endl;
        return;
    }

    std::vector<float> tempRanges(rangeNumber); // Temporary storage for float values
    robotAPI->getLidarRange(tempRanges.data());

    // Copy the first 167 data points
    for (int i = 0; i < (rangeNumber, 167); ++i) {
        ranges[i] = static_cast<double>(tempRanges[i]);
    }
}

/**
 * @brief Returns the number of lidar ranges available.
 * @return The fixed number of lidar ranges (167).
 */
int LidarSensor::getRangeNumber() const {
    return 167; // Fixed number of sensors
}

/**
 * @brief Returns the range (distance) value at a specific index.
 * @param index The index of the range (0-166).
 * @return The range value in meters.
 * @throws std::out_of_range If the index is out of the valid range.
 */
double LidarSensor::getRange(int index) const {
    if (index < 0 || index >= 167) { // Ensure index is within bounds
        throw std::out_of_range("Index out of range in getRange()");
    }
    return ranges[index];
}

/**
 * @brief Finds the maximum range value and its index.
 * @param index Reference to store the index of the maximum range.
 * @return The maximum range value in meters.
 */
double LidarSensor::getMax(int& index) const {
    auto maxIt = std::max_element(ranges.begin(), ranges.begin() + 167);
    index = std::distance(ranges.begin(), maxIt);
    return *maxIt;
}

/**
 * @brief Finds the minimum range value and its index.
 * @param index Reference to store the index of the minimum range.
 * @return The minimum range value in meters.
 */
double LidarSensor::getMin(int& index) const {
    auto minIt = std::min_element(ranges.begin(), ranges.begin() + 167);
    index = std::distance(ranges.begin(), minIt);
    return *minIt;
}

/**
 * @brief Prints all lidar range values to the console.
 */
void LidarSensor::printRanges() const {
    std::cout << "Lidar Ranges:\n";
    for (int i = 0; i < 167; ++i) { // Iterate over all 167 sensors
        std::cout << "  [Sensor " << i << "]: " << ranges[i] << " meters\n";
    }
}

/**
 * @brief Overloaded subscript operator to access lidar range values.
 * @param index The index of the range (0-166).
 * @return The range value in meters.
 * @throws std::out_of_range If the index is out of the valid range.
 */
double LidarSensor::operator[](int index) const {
    return getRange(index);
}

/**
 * @brief Returns the angle for a specific lidar sensor index.
 * @param index The index of the lidar sensor (0-166).
 * @return The angle in degrees corresponding to the sensor index.
 * @throws std::out_of_range If the index is out of the valid range.
 */
double LidarSensor::getAngle(int index) const {
    if (index < 0 || index >= 167) { // Ensure index is within bounds
        throw std::out_of_range("Index out of range in getAngle()");
    }
    double angleIncrement = 240.0 / 167; // Divide 240 degrees across 167 sensors
    return index * angleIncrement - 120.0; // Start at -120, end at +120
}

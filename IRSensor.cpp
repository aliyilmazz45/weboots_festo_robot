// Murat Küçük 22.12.2024
// 152120221117

/**
 * @file IRSensor.cpp
 * @brief Implementation of the IRSensor class.
 */

#include "IRSensor.h"
#include <stdexcept>
#include <iostream> // Debugging output

 /**
  * @brief Constructs an IRSensor object and initializes ranges.
  * @param api Pointer to the robot's API.
  * @throws std::invalid_argument If the provided API pointer is null.
  */
IRSensor::IRSensor(FestoRobotAPI* api) : FestoRobotSensorInterface(api) {
    if (robotAPI == nullptr) {
        throw std::invalid_argument("FestoRobotAPI pointer cannot be null!");
    }
    for (int i = 0; i < 9; i++) {
        ranges[i] = 0.0; // Initialize all sensor ranges to 0
    }
}

/**
 * @brief Retrieves the sensor value for a given index.
 * @param index The sensor index.
 * @return The sensor value (currently returns the index for testing).
 */
double IRSensor::getSensorValue(int index) const {
    return index;
}

/**
 * @brief Retrieves the type of the sensor.
 * @return A string representing the sensor type.
 */
string IRSensor::getSensorType() const {
    return "IR Sensor";
}

/**
 * @brief Retrieves the number of ranges supported by the sensor.
 * @return The number of ranges (currently returns 0 for testing).
 */
int IRSensor::getRangeNumber() const {
    return 0;
}

/**
 * @brief Retrieves the angle of a specific sensor.
 * @param index The sensor index.
 * @return The angle in degrees (currently returns 0.0 for testing).
 */
double IRSensor::getAngle(int index) const {
    return 0.0;
}

/**
 * @brief Updates IR sensor data by retrieving values from the robot API.
 */
void IRSensor::update() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = robotAPI->getIRRange(i);
        std::cout << "Sensor " << i << " distance: " << ranges[i] << " meters" << std::endl;
    }
}

/**
 * @brief Retrieves the distance value from a specific sensor.
 * @param index The sensor index (0-8).
 * @return The distance in meters measured by the sensor.
 * @throws std::out_of_range If the sensor index is outside the range (0-8).
 */
double IRSensor::getRange(int index) const {
    if (index < 0 || index >= 9) {
        throw std::out_of_range("Sensor index out of range (0-8)");
    }
    return ranges[index];
}

/**
 * @brief Overloaded subscript operator for accessing sensor data.
 * @param index The sensor index (0-8).
 * @return The distance in meters measured by the sensor.
 */
double IRSensor::operator[](int index) const {
    return getRange(index);
}

// Ali Yilmaz 152120221108      Tarih: 22.12.2024

/**
 * @file SafeNavigation.h
 * @brief Header file for the SafeNavigation class.
 *
 * This class provides functionality for safe robot navigation, ensuring that the robot
 * avoids obstacles while moving forward or backward using IR sensors.
 */

#pragma once
#include "IRSensor.h"
#include "RobotController.h"
#include <iostream>

 /**
  * @enum MOVESTATE
  * @brief Enum for defining the movement state of the robot.
  *
  * The MOVESTATE enum specifies whether the robot is moving or stopped.
  */
enum MOVESTATE {
    MOVING, /**< The robot is currently moving. */
    STOP    /**< The robot is stopped. */
};

/**
 * @class SafeNavigation
 * @brief A class to handle safe navigation for the robot.
 *
 * The SafeNavigation class ensures the robot moves safely by monitoring the IR sensors
 * for obstacles and stopping if a potential collision is detected.
 */
class SafeNavigation {
private:
    SensorInterface* IR;                  /**< Pointer to the IR sensor. */
    RobotController* controller;          /**< Pointer to the RobotController. */
    MOVESTATE state;                       /**< Current movement state of the robot. */

public:
    /**
     * @brief Constructor for SafeNavigation.
     *
     * @param irSensor Pointer to an IRSensor object.
     * @param robotController Pointer to a RobotController object.
     */
    SafeNavigation(IRSensor* irSensor, RobotController* robotController);

    /**
     * @brief Destructor for SafeNavigation.
     *
     * Ensures resources are properly released to avoid memory leaks.
     */
    ~SafeNavigation();

    /**
     * @brief Moves the robot forward safely.
     *
     * Continuously monitors the IR sensors and stops the robot if an obstacle is detected within a certain distance.
     */
    void moveForwardSafe();

    /**
     * @brief Moves the robot backward safely.
     *
     * Continuously monitors the IR sensors and stops the robot if an obstacle is detected within a certain distance.
     */
    void moveBackwardSafe();
};

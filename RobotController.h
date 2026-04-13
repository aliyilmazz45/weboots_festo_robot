/**
 * @file RobotController.h
 * @brief Declaration of the RobotController class.
 *
 * This file defines the RobotController class, which manages robot operations
 * including movement, sensor management, and access control.
 */

#pragma once
#include "SensorInterface.h"
#include "RobotInterface.h"
#include "RobotOperator.h"
#include <list>

 /**
  * @class RobotController
  * @brief Manages robot operations including movement, sensors, and safe navigation.
  *
  * The RobotController class provides methods to control the robot's movement, manage
  * attached sensors, and handle operator access control.
  */
class RobotController {
private:
    RobotInterface* robot; ///< Pointer to RobotInterface object.
    RobotOperator* robotOperator; ///< Pointer to RobotOperator object.
    std::list<SensorInterface*> sensorList; ///< List of attached sensors.

public:
    /**
     * @brief Constructor for RobotController.
     * @param robot Pointer to a RobotInterface object.
     */
    RobotController(RobotInterface* robot);

    /**
     * @brief Default constructor for RobotController.
     */
    RobotController();

    /**
     * @brief Destructor for RobotController.
     */
    ~RobotController();

    /**
     * @brief Connects the robot.
     * @return True if connection is successful, false otherwise.
     */
    bool connectRobot();

    /**
     * @brief Disconnects the robot.
     * @return True if disconnection is successful, false otherwise.
     */
    bool disconnectRobot();

    /**
     * @brief Stops the robot's movement.
     */
    void stop();

    /**
     * @brief Turns the robot left by 90 degrees.
     */
    void turnLeft();

    /**
     * @brief Turns the robot right by 90 degrees.
     */
    void turnRight();

    /**
     * @brief Moves the robot forward.
     */
    void moveForward();

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward();

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight();

    /**
     * @brief Prints sensor data and robot information.
     */
    void print();

    /**
     * @brief Retrieves the current pose of the robot.
     * @return The current Pose object representing the robot's position and orientation.
     */
    Pose getPose() const;

    /**
     * @brief Updates all attached sensors.
     */
    void updateSensors();

    /**
     * @brief Adds a sensor to the robot.
     * @param sensor Pointer to the sensor to be added.
     */
    void addSensor(SensorInterface* sensor);

    /**
     * @brief Checks access using specific credentials.
     * @param pin The pin number to check access with.
     * @param name The name of the operator.
     * @param surname The surname of the operator.
     * @return True if access is granted, false otherwise.
     */
    bool openAccess(int pin, const std::string& name, const std::string& surname);

    /**
     * @brief Closes access using a specific pin.
     * @param pin The pin number to close access with.
     * @return True if access is closed, false otherwise.
     */
    bool closeAccess(int pin);

    /**
     * @brief Sets the operator for the robot.
     * @param op Pointer to a RobotOperator object.
     */
    void setOperator(RobotOperator* op);
};

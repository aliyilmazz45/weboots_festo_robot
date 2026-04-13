/**
 * @file FestoRobotInterface.h
 * @brief Header file for the FestoRobotInterface class.
 *
 * This file defines the FestoRobotInterface class, which implements the RobotInterface
 * using FestoRobotAPI. It provides functionalities to control and interact with the robot.
 */

#ifndef FESTOROBOTINTERFACE_H
#define FESTOROBOTINTERFACE_H

#include "RobotInterface.h"
#include "FestoRobotAPI.h"

 /**
  * @class FestoRobotInterface
  * @brief Implementation of RobotInterface using FestoRobotAPI.
  *
  * The FestoRobotInterface class provides an implementation for robot control
  * functionalities, such as movement, connection management, and pose handling.
  */
class FestoRobotInterface : public RobotInterface {
private:
    FestoRobotAPI* robotAPI; /**< Pointer to the FestoRobotAPI instance. */

public:
    /**
     * @brief Constructor for FestoRobotInterface.
     * @param api Pointer to an instance of FestoRobotAPI.
     */
    FestoRobotInterface(FestoRobotAPI* api);

    /**
     * @brief Destructor for FestoRobotInterface.
     */
    ~FestoRobotInterface() override;

    /**
     * @brief Turns the robot to the left.
     */
    void turnLeft() override;

    /**
     * @brief Turns the robot to the right.
     */
    void turnRight() override;

    /**
     * @brief Moves the robot forward.
     */
    void moveForward() override;

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight() override;

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft() override;

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward() override;

    /**
     * @brief Stops the robot.
     */
    void stop() override;

    /**
     * @brief Prints the robot's status or information.
     */
    void print() override;

    /**
     * @brief Gets the current pose of the robot.
     * @return The current pose of the robot.
     */
    Pose getPose() override;

    /**
     * @brief Sets the pose of the robot.
     * @param p The pose to set.
     */
    void setPose(Pose p) override;

    /**
     * @brief Connects to the robot.
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot() override;

    /**
     * @brief Disconnects from the robot.
     * @return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot() override;
};

#endif // FESTOROBOTINTERFACE_H

/**
 * @file RobotInterface.h
 * @brief Declaration of the RobotInterface class.
 *
 * This file defines the RobotInterface class, which serves as an abstract base class
 * for controlling a robot. It provides a standardized interface for robot operations.
 */

#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H

#include "Pose.h"

 /**
  * @class RobotInterface
  * @brief Abstract base class for robot control interfaces.
  *
  * The RobotInterface class defines a standardized interface for robot operations,
  * including movement, connection management, and pose handling.
  */
class RobotInterface {
private:
    Pose* position; ///< Pointer to the robot's current position.
    bool connectionStatus; ///< Connection status of the robot.

public:
    /**
     * @brief Virtual destructor for RobotInterface.
     */
    virtual ~RobotInterface() = default;

    /**
     * @brief Turns the robot left by 90 degrees.
     */
    virtual void turnLeft() = 0;

    /**
     * @brief Turns the robot right by 90 degrees.
     */
    virtual void turnRight() = 0;

    /**
     * @brief Moves the robot forward.
     */
    virtual void moveForward() = 0;

    /**
     * @brief Moves the robot backward.
     */
    virtual void moveBackward() = 0;

    /**
     * @brief Moves the robot to the right.
     */
    virtual void moveRight() = 0;

    /**
     * @brief Moves the robot to the left.
     */
    virtual void moveLeft() = 0;

    /**
     * @brief Stops the robot's movement.
     */
    virtual void stop() = 0;

    /**
     * @brief Retrieves the current pose of the robot.
     * @return The robot's current Pose object.
     */
    virtual Pose getPose() = 0;

    /**
     * @brief Sets the robot's pose.
     * @param pose The Pose object to set.
     */
    virtual void setPose(Pose pose) = 0;

    /**
     * @brief Prints the robot's current status or information.
     */
    virtual void print() = 0;

    /**
     * @brief Connects the robot to the system.
     * @return True if the connection is successful, false otherwise.
     */
    virtual bool connectRobot() = 0;

    /**
     * @brief Disconnects the robot from the system.
     * @return True if the disconnection is successful, false otherwise.
     */
    virtual bool disconnectRobot() = 0;

    /**
     * @brief Retrieves the pointer to the robot's current position.
     * @return A pointer to the Pose object representing the robot's position.
     */
    Pose* getPosition() const { return position; }

    /**
     * @brief Sets the robot's position.
     * @param pos Pointer to the Pose object representing the robot's position.
     */
    void setPosition(Pose* pos) { position = pos; }

    /**
     * @brief Retrieves the robot's connection status.
     * @return True if the robot is connected, false otherwise.
     */
    bool getConnectionStatus() const { return connectionStatus; }

    /**
     * @brief Sets the robot's connection status.
     * @param status The connection status to set (true for connected, false for disconnected).
     */
    void setConnectionStatus(bool status) { connectionStatus = status; }
};

#endif // ROBOTINTERFACE_H

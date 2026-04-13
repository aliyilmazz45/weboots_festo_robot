/**
 * @file RobotController.cpp
 * @brief Implementation of the RobotController class for controlling the robot and managing sensors.
 *
 * The RobotController class provides methods for robot movement, connection management,
 * sensor handling, and operator access control.
 */

#include "RobotController.h"
#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Constructs a RobotController object.
 * @param robot Pointer to a RobotInterface object.
 */
RobotController::RobotController(RobotInterface* robot) : robot(robot), robotOperator(nullptr) {}

/**
 * @brief Destructor for the RobotController class.
 *
 * Deletes the robot and robot operator objects to free memory.
 */
RobotController::~RobotController() {
    if (robot) {
        delete robot;
        robot = nullptr;
    }
    if (robotOperator) {
        delete robotOperator;
        robotOperator = nullptr;
    }
}

/**
 * @brief Retrieves the current pose of the robot.
 * @return The current pose of the robot.
 */
Pose RobotController::getPose() const {
    if (robot && robot->getPose().getX() != 0) {
        return robot->getPose();
    }
    return Pose();
}

/**
 * @brief Connects the robot.
 * @return True if the connection is successful, false otherwise.
 */
bool RobotController::connectRobot() {
    if (robot) {
        if (!robot->getConnectionStatus()) {
            if (robot->connectRobot()) {
                cout << "Robot connected successfully." << endl;
                return true;
            }
            else {
                cerr << "Failed to connect the robot." << endl;
            }
        }
        else {
            cout << "Robot is already connected." << endl;
        }
    }
    else {
        cerr << "Robot object is null. Cannot connect." << endl;
    }
    return false;
}

/**
 * @brief Disconnects the robot.
 * @return True if the disconnection is successful, false otherwise.
 */
bool RobotController::disconnectRobot() {
    if (robot) {
        if (robot->getConnectionStatus()) {
            if (robot->disconnectRobot()) {
                cout << "Robot disconnected successfully." << endl;
                return true;
            }
            else {
                cerr << "Failed to disconnect the robot." << endl;
            }
        }
        else {
            cout << "Robot is already disconnected." << endl;
        }
    }
    else {
        cerr << "Robot object is null. Cannot disconnect." << endl;
    }
    return false;
}

/**
 * @brief Stops the robot.
 */
void RobotController::stop() {
    if (robot) {
        robot->stop();
    }
}

/**
 * @brief Turns the robot left.
 */
void RobotController::turnLeft() {
    if (robot) {
        robot->turnLeft();
    }
}

/**
 * @brief Turns the robot right.
 */
void RobotController::turnRight() {
    if (robot) {
        robot->turnRight();
    }
}

/**
 * @brief Moves the robot forward.
 */
void RobotController::moveForward() {
    if (robot) {
        robot->moveForward();
    }
}

/**
 * @brief Moves the robot backward.
 */
void RobotController::moveBackward() {
    if (robot) {
        robot->moveBackward();
    }
}

/**
 * @brief Moves the robot left.
 */
void RobotController::moveLeft() {
    if (robot) {
        robot->moveLeft();
    }
}

/**
 * @brief Moves the robot right.
 */
void RobotController::moveRight() {
    if (robot) {
        robot->moveRight();
    }
}

/**
 * @brief Prints the robot's information and sensor details.
 */
void RobotController::print() {
    if (robot) {
        robot->print();
    }
    for (const auto& sensor : sensorList) {
        if (sensor) {
            cout << "Sensor Type: " << sensor->getSensorType() << endl;
        }
    }
}

/**
 * @brief Updates all sensors managed by the controller.
 */
void RobotController::updateSensors() {
    for (auto& sensor : sensorList) {
        if (sensor) {
            sensor->update();
        }
    }
}

/**
 * @brief Adds a sensor to the controller's list of sensors.
 * @param sensor Pointer to a SensorInterface object.
 */
void RobotController::addSensor(SensorInterface* sensor) {
    if (sensor) {
        sensorList.push_back(sensor);
    }
}

/**
 * @brief Opens access to the robot for the specified operator.
 * @param pin Access code of the operator.
 * @param name Name of the operator.
 * @param surname Surname of the operator.
 * @return True if access is granted, false otherwise.
 */
bool RobotController::openAccess(int pin, const std::string& name, const std::string& surname) {
    if (robotOperator && robotOperator->getName() == name && robotOperator->getSurname() == surname) {
        if (robotOperator->checkAccessCode(pin)) {
            cout << "Access granted for " << name << " " << surname << "." << endl;
            return true;
        }
    }
    cerr << "Access denied. Invalid credentials." << endl;
    return false;
}

/**
 * @brief Closes access to the robot for the specified operator.
 * @param pin Access code of the operator.
 * @return True if access is closed, false otherwise.
 */
bool RobotController::closeAccess(int pin) {
    if (robotOperator && robotOperator->checkAccessCode(pin)) {
        cout << "Access closed successfully." << endl;
        return true;
    }
    cerr << "Access close failed. Invalid pin." << endl;
    return false;
}

/**
 * @brief Sets the operator for the robot controller.
 * @param op Pointer to a RobotOperator object.
 */
void RobotController::setOperator(RobotOperator* op) {
    if (robotOperator) {
        delete robotOperator;
    }
    robotOperator = op;
}

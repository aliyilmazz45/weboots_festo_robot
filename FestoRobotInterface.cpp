#include "FestoRobotInterface.h"
#include <iostream>

using namespace std;



/**
 * @brief Constructs a FestoRobotInterface object with a given API.
 * @param api Pointer to the FestoRobotAPI object.
 */
FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* api) : robotAPI(api) {
    setPosition(new Pose()); // Getter ve Setter ile pozisyon ayarý
    setConnectionStatus(false); // Baþlangýçta baðlantý durumu kapalý
}

/**
 * @brief Destructor for FestoRobotInterface.
 */
FestoRobotInterface::~FestoRobotInterface() {
    if (robotAPI) {
        delete robotAPI;
        robotAPI = nullptr;
    }
    if (getPosition()) {
        delete getPosition();
        setPosition(nullptr);
    }
}

/**
 * @brief Turns the robot left using the API.
 */
void FestoRobotInterface::turnLeft() {
    if (robotAPI) robotAPI->rotate(LEFT);
}

/**
 * @brief Turns the robot right using the API.
 */
void FestoRobotInterface::turnRight() {
    if (robotAPI) robotAPI->rotate(RIGHT);
}

/**
 * @brief Moves the robot forward using the API.
 */
void FestoRobotInterface::moveForward() {
    if (robotAPI) robotAPI->move(FORWARD);
}

/**
 * @brief Moves the robot backward using the API.
 */
void FestoRobotInterface::moveBackward() {
    if (robotAPI) robotAPI->move(BACKWARD);
}

/**
 * @brief Moves the robot left using the API.
 */
void FestoRobotInterface::moveLeft() {
    if (robotAPI) robotAPI->move(LEFT);
}

/**
 * @brief Moves the robot right using the API.
 */
void FestoRobotInterface::moveRight() {
    if (robotAPI) robotAPI->move(RIGHT);
}

/**
 * @brief Gets the robot's current pose.
 * @return The current pose of the robot.
 */
Pose FestoRobotInterface::getPose() {
    if (getPosition() != nullptr) {
        return *getPosition();
    }
    return Pose();
}

/**
 * @brief Sets the robot's current pose.
 * @param p The new pose to set.
 */
void FestoRobotInterface::setPose(Pose p) {
    *getPosition() = p; // Getter kullanýmý
}

/**
 * @brief Connects the robot using the API.
 * @return True if the connection is successful, false otherwise.
 */
bool FestoRobotInterface::connectRobot() {
    if (!getConnectionStatus()) {
        robotAPI->connect();
        setConnectionStatus(true); // Setter kullanýmý
    }
    return getConnectionStatus(); // Getter kullanýmý
}

/**
 * @brief Disconnects the robot using the API.
 * @return True if the disconnection is successful, false otherwise.
 */
bool FestoRobotInterface::disconnectRobot() {
    if (!getConnectionStatus()) {
        robotAPI->disconnect();
        setConnectionStatus(false); // Setter kullanýmý
    }
    return !getConnectionStatus(); // Getter kullanýmý
}

/**
 * @brief Stops the robot.
 */
void FestoRobotInterface::stop() {
    if (robotAPI) robotAPI->stop();
}

/**
 * @brief Prints the current pose of the robot.
 */
void FestoRobotInterface::print() {
    if (getPosition()) {
        cout << "Current Pose: ";
        getPosition()->print(); // Getter kullanýmý
    }
}

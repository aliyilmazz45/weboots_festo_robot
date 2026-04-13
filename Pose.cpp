/**
 * @file Pose.cpp
 * @brief Implementation of the Pose class.
 *
 * This file contains the implementation of the Pose class, which represents the position
 * and orientation of a robot in a 2D plane. It provides methods for setting and retrieving
 * the pose, calculating distances and angles, and performing arithmetic operations.
 */

#include "Pose.h"
#include <cmath>

 /**
  * @brief Constructor that initializes the pose with given values.
  * @param _x X-coordinate of the pose.
  * @param _y Y-coordinate of the pose.
  * @param _th Orientation (angle in degrees) of the pose.
  */
Pose::Pose(double _x, double _y, double _th) : x(_x), y(_y), th(_th) {}

// Getter and Setter Methods

/**
 * @brief Gets the X-coordinate of the pose.
 * @return The X-coordinate.
 */
double Pose::getX() const { return x; }

/**
 * @brief Sets the X-coordinate of the pose.
 * @param _x The new X-coordinate.
 */
void Pose::setX(double _x) { x = _x; }

/**
 * @brief Gets the Y-coordinate of the pose.
 * @return The Y-coordinate.
 */
double Pose::getY() const { return y; }

/**
 * @brief Sets the Y-coordinate of the pose.
 * @param _y The new Y-coordinate.
 */
void Pose::setY(double _y) { y = _y; }

/**
 * @brief Gets the orientation (angle) of the pose.
 * @return The orientation in degrees.
 */
double Pose::getTh() const { return th; }

/**
 * @brief Sets the orientation (angle) of the pose.
 * @param _th The new orientation in degrees.
 */
void Pose::setTh(double _th) { th = _th; }

// getPose and setPose Methods

/**
 * @brief Retrieves the pose components (X, Y, and orientation).
 * @param _x Reference to store the X-coordinate.
 * @param _y Reference to store the Y-coordinate.
 * @param _th Reference to store the orientation (angle in degrees).
 */
void Pose::getPose(double& _x, double& _y, double& _th) const {
    _x = x;
    _y = y;
    _th = th;
}

/**
 * @brief Sets the pose components (X, Y, and orientation).
 * @param _x The new X-coordinate.
 * @param _y The new Y-coordinate.
 * @param _th The new orientation (angle in degrees).
 */
void Pose::setPose(double _x, double _y, double _th) {
    x = _x;
    y = _y;
    th = _th;
}

// Distance and Angle Calculations

/**
 * @brief Calculates the distance from this pose to another pose.
 * @param pos The other pose.
 * @return The Euclidean distance between the two poses.
 */
double Pose::findDistanceTo(const Pose& pos) const {
    return std::sqrt(std::pow(pos.x - x, 2) + std::pow(pos.y - y, 2));
}

/**
 * @brief Calculates the angle from this pose to another pose.
 * @param pos The other pose.
 * @return The angle in degrees.
 */
double Pose::findAngleTo(const Pose& pos) const {
    return std::atan2(pos.y - y, pos.x - x) * 180 / M_PI;
}

// Operator Overloading

/**
 * @brief Compares two poses for equality.
 * @param other The other pose.
 * @return True if the poses are equal, false otherwise.
 */
bool Pose::operator==(const Pose& other) const {
    return (x == other.x) && (y == other.y) && (th == other.th);
}

/**
 * @brief Adds the components of another pose to this pose.
 * @param other The other pose.
 * @return A new Pose object representing the sum.
 */
Pose Pose::operator+(const Pose& other) const {
    return Pose(x + other.x, y + other.y, th + other.th);
}

/**
 * @brief Subtracts the components of another pose from this pose.
 * @param other The other pose.
 * @return A new Pose object representing the difference.
 */
Pose Pose::operator-(const Pose& other) const {
    return Pose(x - other.x, y - other.y, th - other.th);
}

/**
 * @brief Adds the components of another pose to this pose (in-place).
 * @param other The other pose.
 * @return A reference to this pose after addition.
 */
Pose& Pose::operator+=(const Pose& other) {
    x += other.x;
    y += other.y;
    th += other.th;
    return *this;
}

/**
 * @brief Assigns the components of another pose to this pose.
 * @param other The other pose.
 * @return A reference to this pose after assignment.
 */
Pose& Pose::operator-=(const Pose& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        th = other.th;
    }
    return *this;
}

/**
 * @brief Compares two poses for order based on their X and Y coordinates.
 * @param other The other pose.
 * @return True if this pose is less than the other pose, false otherwise.
 */
bool Pose::operator<(const Pose& other) const {
    return (x < other.x) && (y < other.y);
}

// Display Methods

/**
 * @brief Prints the pose information to the console.
 */
void Pose::print() const {
    std::cout << "Pose: (" << x << ", " << y << ", " << th << " degrees)" << std::endl;
}

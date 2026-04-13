/**
 * @file Pose.h
 * @brief Header file for the Pose class.
 *
 * The Pose class represents the position (x, y) and orientation (th) of a robot in a 2D plane.
 * It provides methods to manipulate and retrieve pose information, calculate distances and angles,
 * and perform operator overloading for pose arithmetic.
 */

#ifndef POSE_H
#define POSE_H

#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

 /**
  * @class Pose
  * @brief Represents a 2D position and orientation.
  */
class Pose {
private:
    double x;   /**< X-coordinate of the pose. */
    double y;   /**< Y-coordinate of the pose. */
    double th;  /**< Orientation angle in degrees. */

public:
    /**
     * @brief Constructor to initialize the pose.
     * @param _x X-coordinate (default is 0).
     * @param _y Y-coordinate (default is 0).
     * @param _th Orientation angle in degrees (default is 0).
     */
    Pose(double _x = 0, double _y = 0, double _th = 0);

    // Getter and Setter Methods

    /**
     * @brief Gets the X-coordinate of the pose.
     * @return The X-coordinate.
     */
    double getX() const;

    /**
     * @brief Sets the X-coordinate of the pose.
     * @param _x The new X-coordinate.
     */
    void setX(double _x);

    /**
     * @brief Gets the Y-coordinate of the pose.
     * @return The Y-coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the Y-coordinate of the pose.
     * @param _y The new Y-coordinate.
     */
    void setY(double _y);

    /**
     * @brief Gets the orientation angle of the pose.
     * @return The orientation angle in degrees.
     */
    double getTh() const;

    /**
     * @brief Sets the orientation angle of the pose.
     * @param _th The new orientation angle in degrees.
     */
    void setTh(double _th);

    // getPose and setPose Methods

    /**
     * @brief Retrieves the pose components (X, Y, and orientation).
     * @param _x Reference to store the X-coordinate.
     * @param _y Reference to store the Y-coordinate.
     * @param _th Reference to store the orientation angle in degrees.
     */
    void getPose(double& _x, double& _y, double& _th) const;

    /**
     * @brief Sets the pose components (X, Y, and orientation).
     * @param _x The new X-coordinate.
     * @param _y The new Y-coordinate.
     * @param _th The new orientation angle in degrees.
     */
    void setPose(double _x, double _y, double _th);

    // Distance and Angle Calculations

    /**
     * @brief Calculates the distance from this pose to another pose.
     * @param pos The other pose.
     * @return The Euclidean distance between the two poses.
     */
    double findDistanceTo(const Pose& pos) const;

    /**
     * @brief Calculates the angle from this pose to another pose.
     * @param pos The other pose.
     * @return The angle in degrees.
     */
    double findAngleTo(const Pose& pos) const;

    // Operator Overloading

    /**
     * @brief Checks if two poses are equal.
     * @param other The other pose.
     * @return True if the poses are equal, false otherwise.
     */
    bool operator==(const Pose& other) const;

    /**
     * @brief Adds two poses and returns the result.
     * @param other The other pose.
     * @return A new Pose object representing the sum.
     */
    Pose operator+(const Pose& other) const;

    /**
     * @brief Subtracts another pose from this pose and returns the result.
     * @param other The other pose.
     * @return A new Pose object representing the difference.
     */
    Pose operator-(const Pose& other) const;

    /**
     * @brief Adds another pose to this pose in-place.
     * @param other The other pose.
     * @return A reference to this pose after addition.
     */
    Pose& operator+=(const Pose& other);

    /**
     * @brief Assigns another pose to this pose.
     * @param other The other pose.
     * @return A reference to this pose after assignment.
     */
    Pose& operator-=(const Pose& other);

    /**
     * @brief Compares two poses for ordering based on X and Y coordinates.
     * @param other The other pose.
     * @return True if this pose is less than the other pose, false otherwise.
     */
    bool operator<(const Pose& other) const;

    // Display Methods

    /**
     * @brief Prints the pose information to the console.
     */
    void print() const;
};

#endif // POSE_H

/**
 * @file Point.cpp
 * @brief Implementation of the Point class.
 *
 * This file contains the implementation of the Point class, which provides basic operations for
 * handling 2D points, including setting coordinates, calculating distances, and angles between points.
 */

#include "Point.h"
#include <cmath>

 /**
  * @brief Default constructor.
  *
  * Initializes the point at the origin (0, 0).
  */
Point::Point() : x(0), y(0) {}

/**
 * @brief Parameterized constructor.
 * @param x X-coordinate of the point.
 * @param y Y-coordinate of the point.
 *
 * Initializes the point with the specified coordinates.
 */
Point::Point(double x, double y) : x(x), y(y) {}

/**
 * @brief Retrieves the X-coordinate of the point.
 * @return The X-coordinate.
 */
double Point::getX() const {
    return x;
}

/**
 * @brief Sets the X-coordinate of the point.
 * @param x The new X-coordinate.
 */
void Point::setX(double x) {
    this->x = x;
}

/**
 * @brief Retrieves the Y-coordinate of the point.
 * @return The Y-coordinate.
 */
double Point::getY() const {
    return y;
}

/**
 * @brief Sets the Y-coordinate of the point.
 * @param y The new Y-coordinate.
 */
void Point::setY(double y) {
    this->y = y;
}

/**
 * @brief Sets both the X and Y coordinates of the point.
 * @param x The new X-coordinate.
 * @param y The new Y-coordinate.
 */
void Point::setPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

/**
 * @brief Calculates the distance from this point to another point.
 * @param pos The other point.
 * @return The distance between the two points.
 */
double Point::findDistanceTo(const Point& pos) const {
    return std::sqrt(std::pow(pos.x - x, 2) + std::pow(pos.y - y, 2));
}

/**
 * @brief Calculates the angle from this point to another point.
 * @param pos The other point.
 * @return The angle in radians.
 */
double Point::findAngleTo(const Point& pos) const {
    return std::atan2(pos.y - y, pos.x - x);
}

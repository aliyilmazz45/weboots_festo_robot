/**
 * @file Point.h
 * @brief Declaration of the Point class.
 *
 * This file provides the declaration of the Point class, which represents a 2D point
 * and includes methods for setting and retrieving coordinates, as well as calculating
 * distances and angles to other points.
 */

#ifndef POINT_H
#define POINT_H

 /**
  * @class Point
  * @brief Represents a 2D point with X and Y coordinates.
  *
  * The Point class provides functionality to manage 2D points,
  * including operations such as setting coordinates, calculating
  * distances, and finding angles between points.
  */
class Point {
private:
    double x; ///< X-coordinate of the point.
    double y; ///< Y-coordinate of the point.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the point at the origin (0, 0).
     */
    Point();

    /**
     * @brief Parameterized constructor.
     * @param x X-coordinate of the point.
     * @param y Y-coordinate of the point.
     *
     * Initializes the point with the specified coordinates.
     */
    Point(double x, double y);

    /**
     * @brief Retrieves the X-coordinate of the point.
     * @return The X-coordinate.
     */
    double getX() const;

    /**
     * @brief Sets the X-coordinate of the point.
     * @param x The new X-coordinate.
     */
    void setX(double x);

    /**
     * @brief Retrieves the Y-coordinate of the point.
     * @return The Y-coordinate.
     */
    double getY() const;

    /**
     * @brief Sets the Y-coordinate of the point.
     * @param y The new Y-coordinate.
     */
    void setY(double y);

    /**
     * @brief Sets both the X and Y coordinates of the point.
     * @param x The new X-coordinate.
     * @param y The new Y-coordinate.
     */
    void setPoint(double x, double y);

    /**
     * @brief Calculates the distance from this point to another point.
     * @param pos The other point.
     * @return The distance between the two points.
     */
    double findDistanceTo(const Point& pos) const;

    /**
     * @brief Calculates the angle from this point to another point.
     * @param pos The other point.
     * @return The angle in radians.
     */
    double findAngleTo(const Point& pos) const;
};

#endif // POINT_H

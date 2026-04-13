//Efekan Dursun 22.12.2024
//152120221120

/**
 * @file Map.h
 * @brief Header file for the Map class, representing a grid-based environment.
 *
 * The Map class provides functionalities to manage a 2D grid, including inserting points,
 * setting the robot's position, and displaying the map.
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "Point.h"

 /**
  * @class Map
  * @brief Represents a grid-based map for a robot environment.
  *
  * The Map class manages a 2D grid where each cell can represent empty space, obstacles, or the robot's position.
  */
class Map {
public:
    /**
     * @brief Constructs a Map object.
     * @param numberX Number of grid cells along the X-axis.
     * @param numberY Number of grid cells along the Y-axis.
     * @param gridSize Size of each grid cell in meters.
     */
    Map(int numberX, int numberY, double gridSize);

    /**
     * @brief Marks a point on the map grid as an obstacle.
     * @param point The point to be marked as an obstacle.
     */
    void insertPoint(const Point& point);

    /**
     * @brief Sets the robot's position on the map grid.
     * @param indexX The X-coordinate of the robot in the grid.
     * @param indexY The Y-coordinate of the robot in the grid.
     */
    void setRobotPosition(int indexX, int indexY);

    /**
     * @brief Sets the origin of the grid.
     * @param originX The X-coordinate of the origin.
     * @param originY The Y-coordinate of the origin.
     */
    void setGridOrigin(double originX, double originY);

    /**
     * @brief Returns the entire grid data as a 2D vector.
     * @return A const reference to the grid data.
     */
    const std::vector<std::vector<int>>& getGridData() const;

    /**
     * @brief Gets the value of a specific grid cell.
     * @param indexX The X-coordinate of the grid cell.
     * @param indexY The Y-coordinate of the grid cell.
     * @return The value of the grid cell.
     */
    int getGrid(int indexX, int indexY) const;

    /**
     * @brief Sets the value of a specific grid cell.
     * @param indexX The X-coordinate of the grid cell.
     * @param indexY The Y-coordinate of the grid cell.
     * @param value The value to assign to the grid cell.
     */
    void setGrid(int indexX, int indexY, int value);

    /**
     * @brief Clears the map by resetting all grid cells to zero.
     */
    void clearMap();

    /**
     * @brief Prints basic information about the map, such as dimensions and grid size.
     */
    void printInfo() const;

    /**
     * @brief Displays the map grid in a human-readable format.
     *
     * 'x' represents obstacles, 'R' represents the robot's position, and '.' represents empty cells.
     */
    void showMap() const;

    /**
     * @brief Gets the number of grid cells along the X-axis.
     * @return The number of grid cells along the X-axis.
     */
    int getNumberX() const;

    /**
     * @brief Gets the number of grid cells along the Y-axis.
     * @return The number of grid cells along the Y-axis.
     */
    int getNumberY() const;

    /**
     * @brief Gets the size of each grid cell in meters.
     * @return The grid cell size in meters.
     */
    double getGridSize() const;

    /**
     * @brief Sets the size of each grid cell in meters.
     * @param gridSize The new size for each grid cell.
     */
    void setGridSize(double gridSize);

    /**
     * @brief Gets the X-coordinate of the grid's origin.
     * @return The X-coordinate of the origin.
     */
    double getOriginX() const;

    /**
     * @brief Gets the Y-coordinate of the grid's origin.
     * @return The Y-coordinate of the origin.
     */
    double getOriginY() const;

private:
    int numberX;                          /**< Number of grid cells along the X-axis. */
    int numberY;                          /**< Number of grid cells along the Y-axis. */
    double gridSize;                      /**< Size of each grid cell in meters. */
    std::vector<std::vector<int>> grid;   /**< 2D grid data structure. */
    double originX;                       /**< X-coordinate of the grid's origin. */
    double originY;                       /**< Y-coordinate of the grid's origin. */
};

#endif // MAP_H

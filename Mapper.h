//Efekan Dursun 22.12.2024
//152120221120

/**
 * @file Mapper.h
 * @brief Header file for the Mapper class, which integrates lidar data and robot controller for map management.
 *
 * The Mapper class provides functionalities to update a 2D grid map using lidar sensor data,
 * record the map to a file, and display it in a human-readable format.
 */

#ifndef MAPPER_H
#define MAPPER_H

#include "Map.h"
#include "LidarSensor.h"
#include "RobotController.h"
#include "SensorInterface.h"

 /**
  * @class Mapper
  * @brief Represents a mapping system for a robot environment using lidar data.
  *
  * The Mapper class manages the integration of lidar data with the robot's pose to
  * update and visualize a 2D grid-based map.
  */
class Mapper {
public:
    /**
     * @brief Constructs a Mapper object.
     * @param numberX The number of grid cells along the X-axis.
     * @param numberY The number of grid cells along the Y-axis.
     * @param gridSize The size of each grid cell in meters.
     * @param lidar Pointer to the LidarSensor object.
     * @param ctrl Pointer to the RobotController object.
     */
    Mapper(int numberX, int numberY, double gridSize, LidarSensor* lidar, RobotController* ctrl);

    /**
     * @brief Updates the map using lidar data and the robot's pose.
     *
     * This method clears the existing map, calculates the robot's position on the grid,
     * and marks obstacles on the grid based on the lidar sensor's data.
     */
    void updateMap();

    /**
     * @brief Records the current map to a file.
     * @param fileName The name of the file where the map will be saved.
     *
     * The map is saved as a text file, with "x" representing obstacles,
     * "R" representing the robot's position, and "." representing empty cells.
     */
    void recordMap(const std::string& fileName);

    /**
     * @brief Displays the map in a human-readable format.
     *
     * This method shows the grid on the console with symbols to represent obstacles,
     * the robot's position, and empty cells.
     */
    void showMap() const;

    /**
     * @brief Sets the robot's initial position in the map.
     * @param x The X-coordinate of the robot's starting position in the grid.
     * @param y The Y-coordinate of the robot's starting position in the grid.
     *
     * The robot's position is centered in the grid, and its coordinates are updated
     * in the world coordinate system.
     */
    void setRobotStartPosition(int x, int y);

private:
    Map map;                     /**< The 2D grid map representing the environment. */
    SensorInterface* lidarSensor;    /**< Pointer to the LidarSensor object for lidar data. */
    RobotController* controller; /**< Pointer to the RobotController object for robot control. */
};

#endif // MAPPER_H

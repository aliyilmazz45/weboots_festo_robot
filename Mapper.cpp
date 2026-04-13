//Efekan Dursun 22.12.2024
//152120221120

/**
 * @file Mapper.cpp
 * @brief Implementation of the Mapper class for updating and managing the robot's map.
 *
 * The Mapper class integrates lidar data and robot pose information to update
 * a 2D grid map, record the map to a file, and display the map.
 */

#include "Mapper.h"
#include <cmath>
#include <fstream>

 /**
  * @brief Constructs a Mapper object.
  * @param numberX Number of grid cells along the X-axis.
  * @param numberY Number of grid cells along the Y-axis.
  * @param gridSize Size of each grid cell in meters.
  * @param lidar Pointer to the LidarSensor object.
  * @param ctrl Pointer to the RobotController object.
  */
Mapper::Mapper(int numberX, int numberY, double gridSize, LidarSensor* lidar, RobotController* ctrl)
    : map(numberX, numberY, gridSize), lidarSensor(lidar), controller(ctrl) {
}

/**
 * @brief Updates the map using lidar data and the robot's pose.
 *
 * This method clears the existing map, calculates the robot's position on the grid,
 * and marks obstacles on the grid based on the lidar sensor's data.
 */
void Mapper::updateMap() {
    // Update lidar data
    lidarSensor->update();

    // Clear the map
    map.clearMap();

    // Calculate and set the robot's position on the grid
    int robotGridX = map.getNumberX() / 2; // Center on X-axis
    int robotGridY = map.getNumberY() / 2; // Center on Y-axis
    map.setRobotPosition(robotGridX, robotGridY);

    // Mark obstacles on the map using lidar data
    int lidarCount = lidarSensor->getRangeNumber();

    for (int i = 0; i < lidarCount; ++i) {
        double distance = lidarSensor->getRange(i);
        if (distance <= 0.0) continue;

        double angle = lidarSensor->getAngle(i) + controller->getPose().getTh();

        // Transform to world coordinates
        double worldX = controller->getPose().getX() + distance * cos(angle * M_PI / 180.0);
        double worldY = controller->getPose().getY() + distance * sin(angle * M_PI / 180.0);

        // Account for map origin
        double gridX = (worldX - map.getOriginX()) / map.getGridSize();
        double gridY = (worldY - map.getOriginY()) / map.getGridSize();

        // Add the point to the map
        Point point(gridX, gridY);
        map.insertPoint(point);
    }

    // Display the updated map
    map.showMap();
}

/**
 * @brief Records the current map to a file.
 * @param fileName Name of the file to save the map.
 *
 * This method saves the map grid to a file, using "x" for obstacles,
 * "R" for the robot's position, and "." for empty spaces.
 */
void Mapper::recordMap(const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        const auto& gridData = map.getGridData();
        for (const auto& row : gridData) {
            for (int cell : row) {
                file << (cell == 1 ? "x" : (cell == 2 ? "R" : ".")) << " ";
            }
            file << "\n";
        }
        file.close();
    }
}

/**
 * @brief Displays the current map in a human-readable format.
 */
void Mapper::showMap() const {
    map.showMap();
}

/**
 * @brief Sets the robot's initial position in the map.
 * @param x The X-coordinate of the robot's starting position in the grid.
 * @param y The Y-coordinate of the robot's starting position in the grid.
 *
 * This method centers the robot in the grid and updates its world coordinates.
 */
void Mapper::setRobotStartPosition(int x, int y) {
    // Calculate the center of the grid
    double centerX = map.getNumberX() / 2.0 * map.getGridSize();
    double centerY = map.getNumberY() / 2.0 * map.getGridSize();

    // Set the robot's world position based on the grid's origin
    controller->getPose().setPose(centerX + map.getOriginX(), centerY + map.getOriginY(), 0.0);

    // Place the robot at the center of the grid
    map.setRobotPosition(map.getNumberX() / 2, map.getNumberY() / 2);
}

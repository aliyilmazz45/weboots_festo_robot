//Efekan Dursun 22.12.2024
//152120221120

/**
 * @file Map.cpp
 * @brief Implementation of the Map class for grid-based environment representation.
 */

#include "Map.h"

 /**
  * @brief Constructs a Map object.
  * @param numberX The number of grid cells along the X-axis.
  * @param numberY The number of grid cells along the Y-axis.
  * @param gridSize The size of each grid cell in meters.
  */
Map::Map(int numberX, int numberY, double gridSize)
    : numberX(numberX), numberY(numberY), gridSize(gridSize) {
    grid.resize(numberY, std::vector<int>(numberX, 0)); // Initialize grid with zeros
    originX = -((numberX / 2) * gridSize); // Center the map's origin
    originY = -((numberY / 2) * gridSize);
}

/**
 * @brief Marks a point on the map grid as an obstacle.
 * @param point The point to be marked as an obstacle.
 */
void Map::insertPoint(const Point& point) {
    int xIndex = static_cast<int>(point.getX() / gridSize);
    int yIndex = static_cast<int>(point.getY() / gridSize);

    if (xIndex >= 0 && xIndex < numberX && yIndex >= 0 && yIndex < numberY) {
        grid[yIndex][xIndex] = 1; // Mark as an obstacle
    }
}

/**
 * @brief Sets the robot's position on the map grid.
 * @param indexX The X-coordinate of the robot in the grid.
 * @param indexY The Y-coordinate of the robot in the grid.
 */
void Map::setRobotPosition(int indexX, int indexY) {
    if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) {
        grid[indexY][indexX] = 2; // 2 represents the robot's position
    }
}

/**
 * @brief Returns the grid data as a 2D vector.
 * @return A const reference to the grid data.
 */
const std::vector<std::vector<int>>& Map::getGridData() const {
    return grid;
}

/**
 * @brief Gets the value of a specific grid cell.
 * @param indexX The X-coordinate of the cell.
 * @param indexY The Y-coordinate of the cell.
 * @return The value of the grid cell.
 */
int Map::getGrid(int indexX, int indexY) const {
    return grid[indexY][indexX];
}

/**
 * @brief Sets the value of a specific grid cell.
 * @param indexX The X-coordinate of the cell.
 * @param indexY The Y-coordinate of the cell.
 * @param value The value to set in the grid cell.
 */
void Map::setGrid(int indexX, int indexY, int value) {
    grid[indexY][indexX] = value;
}

/**
 * @brief Clears the map by resetting all grid cells to 0.
 */
void Map::clearMap() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0);
    }
}

/**
 * @brief Prints basic information about the map dimensions and grid size.
 */
void Map::printInfo() const {
    std::cout << "Map Dimensions: " << numberX << "x" << numberY << "\n";
    std::cout << "Grid Size: " << gridSize << "\n";
}

/**
 * @brief Displays the map grid in a human-readable format.
 *
 * 'x' represents obstacles, 'R' represents the robot's position, and
 * '.' represents empty cells.
 */
void Map::showMap() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 1) {
                std::cout << "x "; // Obstacle
            }
            else if (cell == 2) {
                std::cout << "R "; // Robot position
            }
            else {
                std::cout << ". "; // Empty cell
            }
        }
        std::cout << "\n";
    }
}

/**
 * @brief Gets the number of grid cells along the X-axis.
 * @return The number of X-axis grid cells.
 */
int Map::getNumberX() const { return numberX; }

/**
 * @brief Gets the number of grid cells along the Y-axis.
 * @return The number of Y-axis grid cells.
 */
int Map::getNumberY() const { return numberY; }

/**
 * @brief Gets the size of each grid cell in meters.
 * @return The grid cell size in meters.
 */
double Map::getGridSize() const { return gridSize; }

/**
 * @brief Sets the size of each grid cell in meters.
 * @param gridSize The new size for each grid cell.
 */
void Map::setGridSize(double gridSize) { this->gridSize = gridSize; }

/**
 * @brief Sets the origin coordinates of the map.
 * @param originX The X-coordinate of the origin.
 * @param originY The Y-coordinate of the origin.
 */
void Map::setGridOrigin(double originX, double originY) {
    this->originX = originX;
    this->originY = originY;
}

/**
 * @brief Gets the X-coordinate of the map's origin.
 * @return The X-coordinate of the origin.
 */
double Map::getOriginX() const {
    return originX;
}

/**
 * @brief Gets the Y-coordinate of the map's origin.
 * @return The Y-coordinate of the origin.
 */
double Map::getOriginY() const {
    return originY;
}

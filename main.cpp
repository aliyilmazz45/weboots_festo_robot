/**
 * @file main.cpp
 * @brief Entry point for the robot navigation and control system.
 *
 * This file initializes and configures various components for controlling a robot
 * using the FestoRobotAPI, including sensors, controllers, and navigation systems.
 * It also includes a menu-driven interface for interacting with the system.
 */

#include "Menu.h"
#include "FestoRobotAPI.h"
#include "RobotController.h"
#include "SafeNavigation.h"
#include "IRSensor.h"
#include "LidarSensor.h"
#include "Mapper.h"
#include "FestoRobotInterface.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function for the robot control program.
 *
 * This function initializes the robot API and various system components,
 * including sensors, controllers, and the mapper. It then starts the menu-driven
 * user interface for controlling and monitoring the robot.
 *
 * @return int Returns 0 on successful execution, or 1 on failure.
 */
int main() {
    // FestoRobotAPI nesnesini baþlat
    FestoRobotAPI* robotino = new FestoRobotAPI();
    if (!robotino) {
        cerr << "Error: Failed to initialize robotino API." << endl;
        return 1;
    }

    // Robot nesnesi oluþturuluyor
    RobotInterface* robot = new FestoRobotInterface(robotino);

    // RobotController oluþturuluyor
    RobotController* robotController = new RobotController(robot);

    // Diðer sensörler ve yardýmcý nesneler
    IRSensor irSensor(robotino);
    LidarSensor lidarSensor(robotino);
    SafeNavigation safeNav(&irSensor, robotController);
    Mapper mapper(50, 50, 1.0, &lidarSensor, robotController);

    // Baþlangýç pozisyonu ayarlanýyor
    mapper.setRobotStartPosition(25, 25);

    // Menü sistemi baþlatýlýyor
    Menu menu(robotController, &safeNav, &irSensor, &lidarSensor, &mapper);
    menu.run();

    // Bellek temizliði
    delete robotController;
    delete robotino;

    return 0;
}

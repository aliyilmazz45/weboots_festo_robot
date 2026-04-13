/**
 * @file Menu.h
 * @brief Header file for the Menu class.
 *
 * This file defines the Menu class, which provides a console-based interactive
 * interface for controlling the robot system. It includes options for managing
 * robot connections, motion, sensors, mapping, and safe navigation.
 */

#ifndef MENU_H
#define MENU_H

#include "RobotController.h"
#include "SafeNavigation.h"
#include "IRSensor.h"
#include "LidarSensor.h"
#include "Mapper.h"

 /**
  * @class Menu
  * @brief Provides an interactive console-based interface for robot control.
  *
  * The Menu class allows users to interact with the robot system through various
  * menus, handling functionalities like connection management, motion control,
  * sensor updates, mapping, and safe navigation.
  */
class Menu {
private:
    RobotController* controller;   ///< Pointer to RobotController object.
    SafeNavigation* safeNav;       ///< Pointer to SafeNavigation object.
    IRSensor* irSensor;            ///< Pointer to IRSensor object.
    LidarSensor* lidarSensor;      ///< Pointer to LidarSensor object.
    Mapper* mapper;                ///< Pointer to Mapper object.

    /**
     * @brief Displays the main menu options.
     */
    void showMainMenu();

    /**
     * @brief Displays the connection menu options.
     */
    void showConnectionMenu();

    /**
     * @brief Displays the motion menu options.
     */
    void showMotionMenu();

    /**
     * @brief Displays the sensor menu options.
     */
    void showSensorMenu();

    /**
     * @brief Displays the map menu options.
     */
    void showMapMenu();

    /**
     * @brief Displays the safe move menu options.
     */
    void showSafeMoveMenu();

    /**
     * @brief Handles user registration and login.
     */
    void handleUserAuthentication();

public:
    /**
     * @brief Constructs a Menu object.
     * @param ctrl Pointer to the RobotController object.
     * @param nav Pointer to the SafeNavigation object.
     * @param ir Pointer to the IRSensor object.
     * @param lidar Pointer to the LidarSensor object.
     * @param mapper Pointer to the Mapper object.
     */
    Menu(RobotController* ctrl, SafeNavigation* nav, IRSensor* ir, LidarSensor* lidar, Mapper* mapper);

    /**
     * @brief Starts the menu system.
     */
    void run();
};

#endif // MENU_H

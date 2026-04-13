// Ali Yilmaz 152120221108      Tarih: 22.12.2024

/**
 * @file SafeNavigation.cpp
 * @brief Implementation of the SafeNavigation class.
 */

#include "SafeNavigation.h"
#include <thread> // std::this_thread for threading
#include <chrono> // std::chrono for time handling

using namespace std;

/**
 * @brief Constructor for SafeNavigation.
 * @param irSensor Pointer to the IRSensor object.
 * @param robotController Pointer to the RobotController object.
 */
SafeNavigation::SafeNavigation(IRSensor* irSensor, RobotController* robotController)
    : IR(irSensor), controller(robotController), state(STOP) {
}

/**
 * @brief Destructor for SafeNavigation.
 * Ensures that resources are properly released to avoid memory leaks.
 */
SafeNavigation::~SafeNavigation() {
    delete IR;
    delete controller;
}

/**
 * @brief Safely moves the robot forward until an obstacle is detected.
 *
 * This method continuously moves the robot forward while monitoring the front sensors.
 * If any sensor detects an obstacle within 0.3 meters, the robot stops immediately.
 */
void SafeNavigation::moveForwardSafe() {
    if (!IR || !controller) {
        std::cout << "IRSensor or RobotController is not connected!" << std::endl;
        return;
    }

    state = MOVING;
    controller->moveForward();

    while (state == MOVING) {
        IR->update(); // Update sensor readings
        int frontSensors[] = { 0, 1, 2, 7, 8 }; // Indices of front sensors

        for (int i = 0; i < 5; ++i) {
            int sensorIndex = frontSensors[i];
            double distance = IR->getRange(sensorIndex);

            // Debugging message
            std::cout << "Sensor " << sensorIndex << " distance: " << distance << " meters" << std::endl;

            if (distance <= 0.3) {
                controller->stop();
                state = STOP;
                std::cout << "STOP CONDITION TRIGGERED! Sensor " << sensorIndex
                    << " distance: " << distance << " meters. Robot stopped." << std::endl;
                return;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Sensor update frequency
    }
}

/**
 * @brief Safely moves the robot backward until an obstacle is detected.
 *
 * This method continuously moves the robot backward while monitoring the rear sensors.
 * If any sensor detects an obstacle within 0.3 meters, the robot stops immediately.
 */
void SafeNavigation::moveBackwardSafe() {
    if (!IR || !controller) {
        std::cout << "IRSensor or RobotController is not connected!" << std::endl;
        return;
    }

    state = MOVING;
    controller->moveBackward();

    while (state == MOVING) {
        IR->update(); // Update sensor readings
        int backSensors[] = { 2, 3, 4, 5, 6, 7 }; // Indices of back sensors

        for (int i = 0; i < 6; ++i) {
            int sensorIndex = backSensors[i];
            double distance = IR->getRange(sensorIndex);

            // Debugging message
            std::cout << "Sensor " << sensorIndex << " distance: " << distance << " meters" << std::endl;

            if (distance <= 0.3) {
                controller->stop();
                state = STOP;
                std::cout << "STOP CONDITION TRIGGERED! Sensor " << sensorIndex
                    << " distance: " << distance << " meters. Robot stopped." << std::endl;
                return;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Sensor update frequency
    }
}

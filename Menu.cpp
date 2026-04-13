/**
 * @file Menu.cpp
 * @brief Implementation of the Menu class for managing user interaction with the robot system.
 *
 * The Menu class provides a user interface for interacting with the robot's functionalities,
 * including connection, motion, sensors, mapping, and safe navigation.
 */

#include "Menu.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs a Menu object.
 * @param ctrl Pointer to the RobotController object.
 * @param nav Pointer to the SafeNavigation object.
 * @param ir Pointer to the IRSensor object.
 * @param lidar Pointer to the LidarSensor object.
 * @param mapper Pointer to the Mapper object.
 */
Menu::Menu(RobotController* ctrl, SafeNavigation* nav, IRSensor* ir, LidarSensor* lidar, Mapper* mapper)
    : controller(ctrl), safeNav(nav), irSensor(ir), lidarSensor(lidar), mapper(mapper) {
}

/**
 * @brief Runs the main menu loop for user interaction.
 *
 * This method handles the main menu and navigates to submenus based on user input.
 */
void Menu::run() {
    handleUserAuthentication();
    int choice = 0;
    do {
        showMainMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            showConnectionMenu();
            break;
        case 2:
            showMotionMenu();
            break;
        case 3:
            showSensorMenu();
            break;
        case 4:
            showMapMenu();
            break;
        case 5:
            showSafeMoveMenu();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}

/**
 * @brief Handles user authentication for accessing the system.
 *
 * This method creates a new user, assigns it to the controller, and validates the user's credentials.
 */
void Menu::handleUserAuthentication() {
    string name, surname;
    int sifre;

    cout << "=== Kullanici Olustur ===" << endl;
    cout << "Adinizi girin: ";
    cin >> name;
    cout << "Soyadinizi girin: ";
    cin >> surname;
    cout << "Sifre belirleyin: ";
    cin >> sifre;

    RobotOperator* newOperator = new RobotOperator(name, surname, sifre);
    controller->setOperator(newOperator);

    bool accessGranted = false;
    do {
        cout << "=== Kullanici Girisi ===" << endl;
        cout << "Adinizi girin: ";
        cin >> name;
        cout << "Soyadinizi girin: ";
        cin >> surname;
        cout << "Sifre girin: ";
        cin >> sifre;

        if (controller->openAccess(sifre, name, surname)) {
            cout << "Access granted. Welcome, " << name << " " << surname << "!" << endl;
            accessGranted = true;
        }
        else {
            cout << "Bilgiler yanlis! Tekrar deneyin.\n";
        }
    } while (!accessGranted);
}

/**
 * @brief Displays the main menu to the user.
 */
void Menu::showMainMenu() {
    cout << "\n=== Main Menu ===" << endl;
    cout << "1. Connection" << endl;
    cout << "2. Motion" << endl;
    cout << "3. Sensor" << endl;
    cout << "4. Map Operations" << endl;
    cout << "5. Safe Move" << endl;
    cout << "6. Quit" << endl;
    cout << "Choose one: ";
}

/**
 * @brief Displays and handles the connection menu options.
 */
void Menu::showConnectionMenu() {
    int choice = 0;
    do {
        cout << "\n=== Connection Menu ===" << endl;
        cout << "1. Connect Robot" << endl;
        cout << "2. Disconnect Robot" << endl;
        cout << "3. Back" << endl;
        cout << "Choose one: ";
        cin >> choice;

        switch (choice) {
        case 1:
            controller->connectRobot();
            break;
        case 2:
            controller->disconnectRobot();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

/**
 * @brief Displays and handles the motion menu options.
 */
void Menu::showMotionMenu() {
    int choice = 0;
    do {
        cout << "\n=== Motion Menu ===" << endl;
        cout << "1. Move Forward" << endl;
        cout << "2. Move Backward" << endl;
        cout << "3. Stop" << endl;
        cout << "4. Back" << endl;
        cout << "Choose one: ";
        cin >> choice;

        switch (choice) {
        case 1:
            controller->moveForward();
            break;
        case 2:
            controller->moveBackward();
            break;
        case 3:
            controller->stop();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

/**
 * @brief Updates the sensors and displays their status.
 */
void Menu::showSensorMenu() {
    cout << "\n=== Sensor Menu ===" << endl;
    cout << "Updating sensors..." << endl;
    controller->updateSensors();
}

/**
 * @brief Updates and displays the current map.
 */
void Menu::showMapMenu() {
    cout << "\n=== Map Menu ===" << endl;
    mapper->updateMap();
    mapper->showMap();
}

/**
 * @brief Executes safe movement commands.
 */
void Menu::showSafeMoveMenu() {
    cout << "\n=== Safe Move Menu ===" << endl;
    safeNav->moveForwardSafe();
}

// Samet Toka 18.12.2024

/**
 * @file RobotOperator.cpp
 * @brief Implementation of the RobotOperator class.
 */

#include "RobotOperator.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Constructs a RobotOperator object with given name, surname, and access code.
 * @param _name The name of the operator.
 * @param _surname The surname of the operator.
 * @param _accessCode The encrypted access code for the operator.
 */
RobotOperator::RobotOperator(string _name, string _surname, unsigned int _accessCode)
    : name(_name), surname(_surname), accessState(false) {
    Encryption enc;
    accessCode = enc.encrypt(_accessCode); // Þifrelenmiþ þifre atanýyor
}

/**
 * @brief Encrypts the given code using the Encryption class.
 * @param input The code to be encrypted.
 * @return The encrypted code.
 */
int RobotOperator::encryptCode(int input) {
    Encryption code;
    return code.encrypt(input);
}

/**
 * @brief Decrypts the given code using the Encryption class.
 * @param input The code to be decrypted.
 * @return The decrypted code.
 */
int RobotOperator::decryptCode(int input) {
    Encryption code;
    return code.decrypt(input);
}

/**
 * @brief Verifies the access code by decrypting it and comparing it to the input.
 * @param input The input code to check.
 * @return True if the input matches the decrypted access code, false otherwise.
 */
bool RobotOperator::checkAccessCode(int input) {
    Encryption code;
    int decrypted = decryptCode(accessCode);
    accessState = (input == decrypted);
    return accessState;
}

/**
 * @brief Prints the details of the RobotOperator.
 */
void RobotOperator::print() {
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Encrypted Code: " << setw(4) << setfill('0') << accessCode << endl;
}

/**
 * @brief Retrieves the name of the operator.
 * @return The name of the operator.
 */
string RobotOperator::getName() const {
    return name;
}

/**
 * @brief Retrieves the surname of the operator.
 * @return The surname of the operator.
 */
string RobotOperator::getSurname() const {
    return surname;
}

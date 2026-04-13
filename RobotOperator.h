// Samet Toka 18.12.2024

/**
 * @file RobotOperator.h
 * @brief Header file for the RobotOperator class.
 *
 * This file defines the RobotOperator class, which represents an operator who interacts with the robot.
 * The class includes attributes such as name, surname, and an encrypted access code, along with methods
 * for checking access codes and printing operator information.
 */

#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "encryption.h"
using namespace std;

/**
 * @class RobotOperator
 * @brief Represents an operator who interacts with the robot.
 *
 * The RobotOperator class includes attributes such as name, surname, and an encrypted access code.
 * It provides methods for checking access codes and printing operator information.
 */
class RobotOperator {
private:
    string name;           ///< The name of the operator.
    string surname;        ///< The surname of the operator.
    unsigned int accessCode; ///< The encrypted access code for the operator.
    bool accessState;      ///< The access state of the operator (granted or denied).

    /**
     * @brief Encrypts the given code.
     * @param input The code to encrypt.
     * @return The encrypted code.
     */
    int encryptCode(int input);

    /**
     * @brief Decrypts the given code.
     * @param input The code to decrypt.
     * @return The decrypted code.
     */
    int decryptCode(int input);

public:
    /**
     * @brief Constructs a RobotOperator with the given name, surname, and access code.
     * @param _name The name of the operator.
     * @param _surname The surname of the operator.
     * @param _accessCode The encrypted access code for the operator.
     */
    RobotOperator(string _name, string _surname, unsigned int _accessCode);

    /**
     * @brief Checks if the given input matches the decrypted access code.
     * @param input The input code to check.
     * @return True if the input matches the access code, false otherwise.
     */
    bool checkAccessCode(int input);

    /**
     * @brief Prints the details of the operator, including name, surname, and encrypted code.
     */
    void print();

    /**
     * @brief Retrieves the name of the operator.
     * @return The name of the operator.
     */
    string getName() const;

    /**
     * @brief Retrieves the surname of the operator.
     * @return The surname of the operator.
     */
    string getSurname() const;
};

#endif // ROBOTOPERATOR_H

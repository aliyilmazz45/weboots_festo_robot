//152120221085 Samet TOKA 22.12.2024

/**
 * @file encryption.cpp
 * @brief Implementation of the Encryption class for encrypting and decrypting integer codes.
 *
 * This file contains the implementation of the `encrypt` and `decrypt` methods
 * for performing basic encryption and decryption operations on four-digit integer codes.
 */

#include <iostream>
#include "encryption.h"

using namespace std;

/**
 * @brief Encrypts a four-digit integer code.
 *
 * The method takes a four-digit integer input, performs a series of transformations,
 * swaps specific digits, and returns the encrypted result.
 *
 * @param input The four-digit integer code to be encrypted.
 * @return The encrypted integer code.
 */
int Encryption::encrypt(int input) {
    int code[4];

    // Split the input into individual digits
    for (int i = 3; i >= 0; i--) {
        code[i] = input % 10;
        input = input / 10;
    }

    // Perform encryption transformation
    for (int i = 0; i <= 3; i++) {
        code[i] = code[i] + 7;
        code[i] = code[i] % 10;
    }

    // Swap digits
    int x = code[0];
    code[0] = code[2];
    code[2] = x;
    int y = code[1];
    code[1] = code[3];
    code[3] = y;

    // Combine the digits back into an integer
    int encryptedcode = 0;
    for (int i = 0; i <= 3; i++) {
        encryptedcode = (encryptedcode * 10) + code[i];
    }

    return encryptedcode;
}

/**
 * @brief Decrypts an encrypted four-digit integer code.
 *
 * The method takes an encrypted four-digit integer, reverses the encryption transformations,
 * swaps specific digits back to their original positions, and returns the decrypted result.
 *
 * @param input The encrypted four-digit integer code to be decrypted.
 * @return The original decrypted integer code.
 */
int Encryption::decrypt(int input) {
    int code[4];

    // Split the input into individual digits
    for (int i = 3; i >= 0; i--) {
        code[i] = input % 10;
        input = input / 10;
    }

    // Swap digits back to their original positions
    int x = code[0];
    code[0] = code[2];
    code[2] = x;
    int y = code[1];
    code[1] = code[3];
    code[3] = y;

    // Reverse the encryption transformation
    for (int i = 0; i <= 3; i++) {
        code[i] = code[i] + 3;
        code[i] = code[i] % 10;
    }

    // Combine the digits back into an integer
    int decryptedcode = 0;
    for (int i = 0; i <= 3; i++) {
        decryptedcode = (decryptedcode * 10) + code[i];
    }

    return decryptedcode;
}

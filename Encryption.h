//152120221085 Samet TOKA 22.12.2024

/**
 * @file Encryption.h
 * @brief A class for encryption and decryption operations.
 *
 * This file defines the `Encryption` class, which provides methods for
 * encrypting and decrypting integer codes.
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

 /**
  * @class Encryption
  * @brief A class for performing encryption and decryption on integer codes.
  *
  * The `Encryption` class contains methods for securely encrypting an integer code
  * and reversing the process to retrieve the original value.
  */
class Encryption {
public:
    /**
     * @brief Encrypts an integer code.
     * @param code The integer code to be encrypted.
     * @return The encrypted integer code.
     */
    int encrypt(int code);

    /**
     * @brief Decrypts an encrypted integer code.
     * @param code The encrypted integer code to be decrypted.
     * @return The original integer code after decryption.
     */
    int decrypt(int code);
};

#endif // ENCRYPTION_H

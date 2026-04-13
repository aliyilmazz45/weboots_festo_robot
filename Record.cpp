//Ali YILMAZ
//152120221108
/**
 * @file Record.cpp
 * @brief Implementation of the Record class for file operations.
 */

#include "Record.h"
#include <iostream>

 /**
  * @brief Default constructor for the Record class.
  */
Record::Record() {}

/**
 * @brief Sets the name of the file to be used for operations.
 * @param name Name of the file.
 */
void Record::setFileName(const std::string& name) {
    fileName = name;
}

/**
 * @brief Opens the file in append mode for reading and writing.
 * @return True if the file is successfully opened, false otherwise.
 */
bool Record::openFile() {
    file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    return file.is_open();
}

/**
 * @brief Closes the file if it is open.
 */
void Record::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}

/**
 * @brief Reads a single line from the file.
 * @return The line read from the file, or an empty string if no line is read.
 */
std::string Record::readLine() {
    std::string line;
    if (file.is_open() && std::getline(file, line)) {
        return line;
    }
    return "";
}

/**
 * @brief Writes a single line to the file.
 * @param line The line to write to the file.
 */
void Record::writeLine(const std::string& line) {
    if (file.is_open()) {
        file << line << "\n";
    }
}

/**
 * @brief Overloads the << operator to output file information.
 * @param os The output stream.
 * @param record The Record object to output.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, const Record& record) {
    os << "File: " << record.fileName;
    return os;
}

/**
 * @brief Overloads the >> operator to input file information.
 * @param is The input stream.
 * @param record The Record object to input into.
 * @return The modified input stream.
 */
std::istream& operator>>(std::istream& is, Record& record) {
    is >> record.fileName;
    return is;
}

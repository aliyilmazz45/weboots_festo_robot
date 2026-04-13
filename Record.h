//Ali YILMAZ
//152120221108
/**
 * @file Record.h
 * @brief Declaration of the Record class for file operations.
 */

#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <fstream>

 /**
  * @class Record
  * @brief Manages file operations such as reading, writing, and file handling.
  */
class Record {
private:
    std::string fileName; ///< Name of the file for operations.
    std::fstream file;    ///< File stream for reading and writing.

public:
    /**
     * @brief Default constructor for the Record class.
     */
    Record();

    /**
     * @brief Sets the name of the file to be used for operations.
     * @param name The name of the file.
     */
    void setFileName(const std::string& name);

    /**
     * @brief Opens the file in append mode for reading and writing.
     * @return True if the file is successfully opened, false otherwise.
     */
    bool openFile();

    /**
     * @brief Closes the file if it is open.
     */
    void closeFile();

    /**
     * @brief Reads a single line from the file.
     * @return The line read from the file, or an empty string if no line is read.
     */
    std::string readLine();

    /**
     * @brief Writes a single line to the file.
     * @param line The line to write to the file.
     */
    void writeLine(const std::string& line);

    /**
     * @brief Overloads the << operator to output file information.
     * @param os The output stream.
     * @param record The Record object to output.
     * @return The modified output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Record& record);

    /**
     * @brief Overloads the >> operator to input file information.
     * @param is The input stream.
     * @param record The Record object to input into.
     * @return The modified input stream.
     */
    friend std::istream& operator>>(std::istream& is, Record& record);
};

#endif // RECORD_H

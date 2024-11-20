#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include "../../domain/logger/ILogger.hpp"

#include <iostream>
#include <fstream>

namespace logger {
    /**
     * @class FileLogger
     * @brief A class that represents a logger that writes to a file
     */
    class FileLogger : public ILogger {
    public:
        explicit FileLogger(const char* file_name);
        FileLogger(const FileLogger& other) = delete;
        FileLogger& operator=(const FileLogger& other) = delete;
        FileLogger(FileLogger&& other) noexcept = delete;// Move assignment
        FileLogger& operator=(FileLogger&& other) noexcept = delete;
        ~FileLogger() override;

        /**
         * @brief Writes a line to the file
         * @param line The line to write
         */
        void log(const char* message) override;

        /**
         * @brief Writes a line to the file
         * @param line The line to write
         */
        void operator<<(const char* message) override;
    private:
        std::ofstream filestream_;
    };

} // logger

#endif //FILELOGGER_HPP

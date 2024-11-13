#include "FileLogger.hpp"

namespace logger {

    FileLogger::FileLogger(const char* file_name) {
        filestream_.open(file_name, std::ios::out | std::ios::app);
        if (!filestream_.is_open()) {
            std::cerr << "Kan bestand niet openen of aanmaken: " << file_name << std::endl;
        }
    }

    FileLogger::~FileLogger() {
        filestream_.close();
    }

    void FileLogger::log(const char* line) {
        filestream_ << line << std::endl;
    }

    void FileLogger::operator<<(const char* line) {
        filestream_ << line << std::endl;
    }

    void FileLogger::close() {
        filestream_.close();
    }
} // logger
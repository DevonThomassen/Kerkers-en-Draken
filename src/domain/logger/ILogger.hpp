#ifndef ILOGGER_HPP
#define ILOGGER_HPP

/**
 * @namespace logger
 * @brief Contains logging functionality
 */
namespace logger {

    /**
     * @brief Interface for logging
     */
    class ILogger {
    public:
        virtual ~ILogger() = default;

        /**
         * @brief Writes a line to the log
         * @param message The line to write
         */
        virtual void log(const char* message) = 0;

        /**
         * @brief Writes a line to the log
         * @param message The line to write
         */
        virtual void operator<<(const char* message) = 0;
    };

} // logger

#endif //ILOGGER_HPP

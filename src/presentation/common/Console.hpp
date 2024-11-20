#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "../commands/CommandKey.h"
#include "../commands/incl/CommandInvoker.hpp"

using namespace presentation::commands;

/**
 * @brief Contains functionality for the console
 */
namespace presentation::console {

    /**
     * @brief Splits a string into a vector of strings
     * @param str The string to splits
     * @return A vector of strings
     */
    [[nodiscard]] std::vector<std::string> splits(const std::string& str);

    /**
     * @brief Get the command key from the input
     * @param input The input
     * @return The command key
     */
    [[nodiscard]] CommandKeyAndArguments get_command_key(const std::string& input);

    /**
     * @brief Print a message
     * @param message The message
     */
    void print(const std::string& message);

    /**
     * @brief Print an error
     * @param message The error
     */
    void error(const std::string& error);

    /**
     * @brief Get the input
     * @return The input
     */
    [[nodiscard]] std::string get_input();

    /**
     * @brief Get the input
     * @return The input
     */
    [[nodiscard]] std::optional<int> get_input_as_int();
}

#endif //CONSOLE_HPP

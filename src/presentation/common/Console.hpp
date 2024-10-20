#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "../commands/CommandKey.h"
#include "../commands/incl/CommandInvoker.hpp"

using namespace presentation::commands;

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
    [[nodiscard]] CommandKey get_command_key(const std::string& input);

    /**
     * @brief Get the command key and arguments from the input
     * @param input The input
     * @return The command key and arguments
     */
    [[nodiscard]] CommandKeyAndArguments get_command_key_and_arguments(const std::string& input);

    /**
     * @brief Print a message
     * @param message The message
     */
    void print(const std::string& message);

    /**
     * @brief Get the input
     * @return The input
     */
    [[nodiscard]] std::string get_input();
}

#endif //CONSOLE_HPP

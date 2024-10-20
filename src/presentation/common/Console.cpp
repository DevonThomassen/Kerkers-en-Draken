#include "Console.hpp"

#include <sstream>

namespace presentation::console {

    std::vector<std::string> splits(const std::string& str) {
        std::vector<std::string> result;
        std::istringstream iss(str);
        std::string word;

        while (iss >> word) {
            result.push_back(word);
        }
        return result;
    }

    CommandKey get_command_key(const std::string& input) {
        const auto words = splits(input);
        if (words.empty()) {
            return CommandKey::UNKNOWN;
        }

        const auto& command = words[0];
        if (command == "help") {
            return CommandKey::HELP;
        }
        if (command == "start") {
            return CommandKey::START;
        }
        if (command == "exit" or command == "quit") {
            return CommandKey::EXIT;
        }
        if (command == "look") {
            return CommandKey::LOOK;
        }
        return CommandKey::UNKNOWN;
    }

    CommandKeyAndArguments get_command_key_and_arguments(const std::string& input) {
        return CommandKeyAndArguments {
            .key = get_command_key(input),
            .arguments = splits(input)
        };
    }

    void print(const std::string& message) {
        std::cout << message;
    }

    std::string get_input() {
        std::string input;
        std::getline(std::cin, input);
        return std::move(input);
    }
} // presentation
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
        if (command == "kijk") {
            return CommandKey::LOOK;
        }
        if (command == "zelf") {
            return CommandKey::SELF;
        } if (command == "ga") {
            return CommandKey::GO;
        }
        return CommandKey::UNKNOWN;
    }

    CommandKeyAndArguments get_command_key_and_arguments(const std::string& input) {
        return CommandKeyAndArguments{
                .key = get_command_key(input),
                .arguments = splits(input)
        };
    }

    void print(const std::string& message) {
        std::cout << message;
    }

    void error(const std::string& error) {
        std::cerr << error;
    }

    std::string get_input() {
        std::string input;
        std::getline(std::cin, input);
        return std::move(input);
    }

    std::optional<int> get_input_as_int() {
        std::string input;
        std::getline(std::cin, input);
        try {
            const auto parsed = std::stoi(input);
            return std::make_optional(parsed);
        } catch (const std::exception& e) {
            console::error(e.what());
            return std::nullopt;
        }
    }
} // presentation
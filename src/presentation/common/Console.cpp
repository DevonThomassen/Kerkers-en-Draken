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

    CommandKeyAndArguments get_command_key(const std::string& input) {
        const auto words = splits(input);
        if (words.empty()) {
            return {
                    .key = CommandKey::UNKNOWN
            };
        }

        const auto& command = words[0];
        std::string arguments;
        if (words.size() > 1) {
            for (size_t i = 1; i < words.size(); ++i) {
                if (i > 1) {
                    arguments += " ";
                }
                arguments += words[i];
            }
        }
        if (command == "help") {
            return {CommandKey::HELP};
        }
        if (command == "start") {
            return {CommandKey::START};
        }
        if (command == "exit" or command == "quit") {
            return {CommandKey::EXIT};
        }
        if (command == "kijk") {
            return {
                    CommandKey::LOOK,
                    arguments
            };
        }
        if (command == "zelf") {
            return {CommandKey::SELF};
        }
        if (command == "ga") {
            return {
                    CommandKey::GO,
                    arguments
            };
        }
        if (command == "pak") {
            return {
                    CommandKey::TAKE,
                    arguments
            };
        }
        if (command == "zoek") {
            return {CommandKey::SEARCH};
        }
        if (command == "leg") {
            return {CommandKey::PUT};
        }
        return {CommandKey::UNKNOWN};
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
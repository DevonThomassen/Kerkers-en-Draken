#include "../incl/UnknownCommand.hpp"

#include "common/Console.hpp"

namespace presentation::commands {
    void UnknownCommand::execute(const std::string& arguments) {
        console::print("Onbekende commando.\n");
    }
} // presentation::commands

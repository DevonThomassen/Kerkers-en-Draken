#include "../incl/UnknownCommand.hpp"

#include "common/Console.hpp"

namespace presentation::commands {
    void UnknownCommand::execute() {
        console::print("Onbekende commando.\n");
    }
} // presentation::commands

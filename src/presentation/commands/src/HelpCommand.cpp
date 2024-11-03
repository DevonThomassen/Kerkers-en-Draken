#include "../incl/HelpCommand.hpp"

#include "common/Console.hpp"

namespace presentation::commands {

    void HelpCommand::execute() {
        console::print("Help command\n");
    }

} // presentation::commands

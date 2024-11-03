#include "../incl/HelpCommand.hpp"

#include "common/Console.hpp"

namespace presentation::commands {
    
    void HelpCommand::execute(const std::string& arguments) {
        console::print("Help command\n");
    }
} // presentation::commands

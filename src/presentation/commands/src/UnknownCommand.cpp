#include "../incl/UnknownCommand.hpp"

namespace presentation::commands {
    void UnknownCommand::execute() {
        std::cout << "Unknown command\n";
    }
} // presentation::commands

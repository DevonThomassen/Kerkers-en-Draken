#include "../incl/WaitCommand.hpp"

#include "common/Console.hpp"

namespace presentation::commands {

    WaitCommand::WaitCommand() = default;

    void WaitCommand::execute(const std::string& arguments) {
        console::print("Wachten...\n");
    }
} // presentation::commands

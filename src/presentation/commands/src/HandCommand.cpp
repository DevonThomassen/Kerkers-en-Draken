#include "../incl/HandCommand.hpp"

#include "common/Console.hpp"
#include "common/Player.hpp"

namespace presentation::commands {

    HandCommand::HandCommand(std::unique_ptr<Player>& player)
            : player_(player) {}

    void HandCommand::execute(const std::string& arguments) {
        if (arguments.empty()) {
            console::print("Deze command heeft een argument nodig.\n");
            return;
        }
        player_->equip_in_hand(arguments);
    }

} // presentation::commands
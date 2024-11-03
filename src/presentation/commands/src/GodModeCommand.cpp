#include "../incl/GodModeCommand.hpp"

#include "common/Console.hpp"
#include "common/Player.hpp"

namespace presentation::commands {
    GodModeCommand::GodModeCommand(std::unique_ptr<Player>& player)
            : player_{player} {}

    void GodModeCommand::execute(const std::string& arguments) {
        player_->toggle_god_mode();
        if (player_->is_god_mode()) {
            console::print("Godmdmode ingeschakeld!\n");
        } else {
            console::print("Godmode uitgeschakeld!\n");
        }
    }

} // presentation::commands


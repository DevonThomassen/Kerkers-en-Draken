#include "../incl/SelfCommand.hpp"

namespace presentation::commands {

    SelfCommand::SelfCommand(std::unique_ptr<Player>& player)
            : player_(player) {
    }

    void SelfCommand::execute() {
        console::print(std::format("Je hebt %d levenspunten\n", player_->get_health()));
        console::print(std::format("Je hebt een aanvalskans van %d\n", player_->get_attack_chance()));
        console::print(std::format("Je hebt de volgende wapen vast: \n"));
        console::print(std::format("Je draagt de volgende wapenuitrusting: \n"));
        console::print(std::format("Je hebt %d goudstukken: \n"));
        console::print(std::format("Je bezit bestaat uit de volgende objecten: \n"));
    }

} // presentation::commands
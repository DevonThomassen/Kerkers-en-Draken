#include "../incl/SelfCommand.hpp"

namespace presentation::commands {

    SelfCommand::SelfCommand(std::unique_ptr<Player>& player)
            : player_(player) {
    }

    void SelfCommand::execute() {
        console::print(std::format("Je hebt %d levenspunten\n", player_->get_health()));
        console::print(std::format("Je hebt een aanvalskans van %d\n", player_->get_attack_chance()));
        console::print(std::format("Je hebt de volgende wapen vast: \n", player_->get_weapon_name()));
        console::print(std::format("Je draagt de volgende wapenuitrusting: \n", player_->get_armour_name()));
        console::print(std::format("Je hebt %d goudstukken: \n", player_->get_gold()));
        console::print(std::format("Je bezit bestaat uit de volgende objecten: \n", player_->get_consumable_names()));
    }

} // presentation::commands
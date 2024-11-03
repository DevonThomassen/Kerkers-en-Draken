#include "../incl/LookCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "common/Player.hpp"
#include "../domain/common/Location.hpp"
#include "gameobject/incl/EnemyObject.hpp"

namespace presentation::commands {

    LookCommand::LookCommand(std::shared_ptr<GameService> game_service,
                             std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {}

    void LookCommand::execute(const std::string& arguments) {
        if (arguments.empty()) {
            look_room();
            return;
        }
        if (arguments == "zelf") {
            look_self();
            return;
        }
        look_item(arguments);
        look_enemy(arguments);
    }

    void LookCommand::look_room() {
        const auto location = game_service_->get_current_location_ptr();
        console::print(location->simple_description());
        console::print(std::format("Mogelijke richting(en): {} \n",
                                   std::string(location->get_possible_directions())));

        const auto& array = location->get_objects();
        for (int i = 0; i < array.size(); i++) {
            auto object = array[i];
            if (!object->is_invisible()) {
                const auto enemy = dynamic_cast<game_objects::EnemyObject*>(object);
                if (enemy != nullptr) {
                    console::print(std::format("Vijand: {}\n", object->get_name()));
                } else {
                    console::print(std::format("Zichtbare object: {}\n", object->get_name()));
                }
            }
        }
    }

    void LookCommand::look_self() {
        console::print(std::format("Gegevens van {}: \n", player_->get_name()));
        console::print(std::format("Je hebt {} levenspunten\n", player_->get_health()));
        console::print(std::format("Je hebt een aanvalskans van {}%\n", player_->get_attack_chance()));
        console::print(std::format("Je hebt de volgende wapen vast: {} \n", player_->get_weapon_name()));
        console::print(std::format("Je draagt de volgende wapenuitrusting: {} \n", player_->get_armour_name()));
        console::print(std::format("Je hebt {} goudstukken: \n", player_->get_gold()));
        console::print(std::format("Je bezit bestaat uit de volgende objecten: {} \n", player_->get_all_objects_names()));
    }

    bool LookCommand::look_item(const std::string& name) {
        const auto location = game_service_->get_current_location_ptr();
        const auto& array = location->get_objects();
        for (int i = 0; i < array.size(); i++) {
            auto object = array[i];
            if (dynamic_cast<game_objects::EnemyObject*>(array[i]) != nullptr) {
                continue;
            }
            if (!object->is_invisible()
                && name == object->get_name()) {
                console::print(std::format("{}: {}\n", object->get_name(), object->get_description()));
                return true;
            }
        }
        return false;
    }

    bool LookCommand::look_enemy(const std::string& name) {
        const auto location = game_service_->get_current_location_ptr();
        const auto& array = location->get_objects();
        for (int i = 0; i < array.size(); i++) {
            const auto enemy = dynamic_cast<game_objects::EnemyObject*>(array[i]);
            if (enemy != nullptr
                && name == enemy->get_name()) {
                if (enemy->get_health() <= 0) {
                    console::print(std::format("{} is dood\n", enemy->get_name()));
                    game_service_->get_current_location_ptr()->search_room();
                } else {

                    console::print(
                            std::format("{} ({}hp): {}\n", enemy->get_name(), enemy->get_health(),
                                        enemy->get_description()));
                    return true;
                }
            }
        }
        return false;
    }

} // presentation::commands

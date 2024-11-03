#include <utility>

#include "../incl/AttackCommand.hpp"

#include "../../../application/GameService.hpp"
#include "common/Player.hpp"
#include "common/Console.hpp"
#include "gameobject/incl/EnemyObject.hpp"
#include "../domain/common/Location.hpp"

namespace presentation::commands {

    AttackCommand::AttackCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {
    }

    void AttackCommand::execute(const std::string& arguments) {
        const auto array = game_service_->get_current_location().get_objects();
        const auto player_damage = player_->do_attack();
        if (player_damage == 0) return;
        for (int i = 0; i < array.size(); i++) {
            auto object = array[i];
            if (object->get_name() == arguments) {
                if (const auto enemy = dynamic_cast<EnemyObject*>(object)) {
                    if (enemy->get_health() > 0) {
                        console::print(std::format("Je doet {} damage.", player_damage));
                        enemy->take_damage(player_damage);
                    }
                }
            }
        }
    }

} // presentation::commands

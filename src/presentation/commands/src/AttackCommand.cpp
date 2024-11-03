#include "../incl/AttackCommand.hpp"

#include "../../../application/GameService.hpp"
#include "common/Player.hpp"
#include "common/Console.hpp"
#include "gameobject/incl/GameObject.hpp"
#include "../domain/common/Location.hpp"

namespace presentation::commands {

    AttackCommand::AttackCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player)
            : game_service_(game_service),
              player_(player) {
    }

    void AttackCommand::execute(const std::string& arguments) {
    }

} // presentation::commands

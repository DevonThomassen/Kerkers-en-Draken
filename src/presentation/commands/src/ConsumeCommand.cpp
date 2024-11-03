#include "../incl/ConsumeCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Location.hpp"
#include "gameobject/incl/ConsumableObject.hpp"
#include "common/Player.hpp"

namespace presentation::commands {

    ConsumeCommand::ConsumeCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)), player_(player) {

    }

    void ConsumeCommand::execute(const std::string& arguments) {
        const auto game_object = player_->remove_object(arguments);
        if (game_object == nullptr) {
            console::error("Dit object bestaat niet\n");
            return;
        }

        const auto consumable = dynamic_cast<game_objects::ConsumableObject*>(game_object);
        if (consumable != nullptr) {
            switch (player_->consume(consumable)) {
                case 1:
                    game_service_->teleport(consumable->get_value());
                    break;
                case -1:
                default:
                    console::print("Object niet gevonden\n");
                    break;
            }
        } else {
            console::error("Dit object kan niet geconsumeerd worden\n");
        }
    }
} // presentation::commands
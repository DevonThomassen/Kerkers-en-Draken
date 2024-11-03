#include "../incl/TakeCommand.hpp"

#include "../application/GameService.hpp"
#include "../domain/common/Location.hpp"
#include "common/Console.hpp"
#include "common/Player.hpp"

namespace presentation::commands {

    TakeCommand::TakeCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {

    }

    void TakeCommand::execute(const std::string& arguments) {
        const auto game_object = game_service_->get_current_location().take_object(arguments.c_str());
        if (game_object == nullptr) {
            console::error("Dit object bestaat niet\n");
            return;
        }
        player_->add_object(game_object);
    }

} // presentation::commands
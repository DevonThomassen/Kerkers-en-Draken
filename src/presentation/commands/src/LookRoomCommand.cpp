#include "../incl/LookRoomCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Location.hpp"


namespace presentation::commands {

    LookRoomCommand::LookRoomCommand(std::shared_ptr<GameService> game_service,
                                     std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {}

    void LookRoomCommand::execute() {
        console::print(std::format("Mogelijke richting(en): {} \n",
                                   std::string(game_service_->get_current_location().get_possible_directions())));

    }

} // presentation::commands
#include "../incl/CheckRoomCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Location.hpp"

namespace presentation::commands {

    CheckRoomCommand::CheckRoomCommand(std::shared_ptr<GameService> game_service)
            : game_service_(std::move(game_service)) {
    }

    void CheckRoomCommand::execute(const std::string& arguments) {
        console::print(game_service_->get_current_location().simple_description());
    }

} // presentation::commands
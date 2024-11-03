#include "../incl/ExitCommand.hpp"

#include "../../../application/GameService.hpp"
#include "common/Console.hpp"

using namespace application;

namespace presentation::commands {

    ExitCommand::ExitCommand(std::shared_ptr<GameService> game_service_)
            : game_service_(std::move(game_service_)) {

    }

    void ExitCommand::execute(const std::string& arguments) {
        game_service_->exit();
        console::print("Exiting the game...\n");
    }

} // presentation::commands

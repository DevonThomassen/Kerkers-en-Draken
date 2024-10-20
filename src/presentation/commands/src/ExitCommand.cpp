#include "../incl/ExitCommand.hpp"

using namespace application;

namespace presentation::commands {

    ExitCommand::ExitCommand(std::shared_ptr<GameService> game_service_)
            : game_service_(std::move(game_service_)) {

    }

    void ExitCommand::execute() {
        game_service_->exit();
        std::cout << "Exiting the game...\n";
    }

} // presentation::commands

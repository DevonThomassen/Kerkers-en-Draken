#include "commands/incl/StartCommand.hpp"

#include <iostream>
#include <filesystem>
#include <utility>

namespace presentation::commands {

    StartCommand::StartCommand(std::shared_ptr<GameService> gameService)
        : gameService_(std::move(gameService)), default_path(std::filesystem::current_path().string() + "/resources") {
    }

    void StartCommand::execute() {
        if (gameService_->is_running()) {
            std::cout << "Game is already running.\n";
            return;
        }
        std::cout << "Starting the game...\n";
        const auto path = default_path + "/kasteelruine.xml";
        gameService_->start(path.c_str());
    }

} // presentation::commands
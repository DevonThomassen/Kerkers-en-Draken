#include "commands/incl/StartCommand.hpp"

#include <filesystem>
#include <utility>

#include "../../../application/GameService.hpp"
#include "common/Console.hpp"

namespace presentation::commands {

    StartCommand::StartCommand(std::shared_ptr<GameService> gameService)
            : gameService_(std::move(gameService)),
              default_path(std::filesystem::current_path().string() + "/resources") {
    }

    void StartCommand::execute(const std::string& arguments) {
        if (gameService_->is_running()) {
            console::print("Game is already running.\n");
            return;
        }
        console::print("Starting the game...\n");
        const auto path = default_path + "/kasteelruine.xml";
        gameService_->start(path.c_str());
    }

} // presentation::commands
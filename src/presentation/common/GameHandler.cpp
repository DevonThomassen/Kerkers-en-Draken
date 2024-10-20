#include "common/GameHandler.hpp"

const auto print = [](const std::string& str) {
    presentation::console::print(str);
};

const auto get_input = []() {
    return presentation::console::get_input();
};

namespace presentation {

    GameHandler::GameHandler()
            : gameService_(std::shared_ptr<application::GameService>()),
              invoker_(std::make_unique<CommandInvoker>(gameService_)),
              player_(nullptr){}

    void GameHandler::start() {
        console::print("Choose a player name: ");
        const auto playerName = get_input();
        player_ = std::make_unique<Player>(playerName);
        gameService_->start();
        gameService_->main_loop([&]() {
            this->iterate();
        });
    }

    void GameHandler::iterate() {
        print("Enter a command: ");
        const auto commandKey = console::get_command_key(console::get_input());
        invoker_->invoke(commandKey);
    }

} // presentation
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
              player_(nullptr) {}

    void GameHandler::start() {
        set_start_up();
        set_player();

        gameService_->main_loop([&]() {
            this->iterate();
        });
    }

    void GameHandler::set_start_up() {
        console::print("Welkom bij het spel!\n");
        console::print(
                "Als je het spel wilt genereren type `gen` anders voer hier het pad naam in van het bestand: \n");
        const auto path = console::get_input();

        if (path == "gen") {
            generate_locations();
        } else {
            gameService_->start(path.c_str());
        }
    }

    void GameHandler::generate_locations() {
        while (true) {
            console::print("Hoeveel locaties wil je genereren? ");
            const auto amount = console::get_input_as_int();
            if (amount.has_value()) {
                gameService_->start(amount.value());
                return;
            }
            console::print("Ongeldige invoer, probeer opnieuw.\n");
        }
    }

    void GameHandler::set_player() {
        console::print("Choose a player name: ");
        const auto playerName = get_input();
        player_ = std::make_unique<Player>(playerName);
    }

    void GameHandler::iterate() {
        print("Enter a command: ");
        const auto commandKey = console::get_command_key(console::get_input());
        invoker_->invoke(commandKey);
    }

} // presentation
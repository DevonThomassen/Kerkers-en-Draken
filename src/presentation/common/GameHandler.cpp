#include "common/GameHandler.hpp"
#include "../domain/common/Location.hpp"
#include "../infrastructure/logger/FileLogger.hpp"

const auto print = [](const std::string& str) {
    presentation::console::print(str);
};

const auto get_input = []() {
    return presentation::console::get_input();
};

namespace presentation {

    GameHandler::GameHandler(std::unique_ptr<ILogger> logger)
            : logger_(std::move(logger)),
              gameService_(nullptr),
              invoker_(nullptr),
              player_(nullptr) {}

    void GameHandler::start() {
        gameService_ = std::make_shared<application::GameService>();
        set_start_up();
        set_player();
        invoker_ = std::make_unique<CommandInvoker>(player_, gameService_);

        console::print("Het spel begint!\n");
        const auto& start_location = gameService_->get_current_location();
        console::print(start_location.name());
        console::print(start_location.simple_description());
        gameService_->main_loop([&]() {
            this->iterate();
        });
        console::print("Wil je opnieuw spelen? Typ `opnieuw` om opnieuw te spelen.\n");
        if (console::get_input() == "opnieuw") {
            start();
        }
        console::print("Spel is afgelopen.\n");
    }

    void GameHandler::set_start_up() {
        console::print("Welkom bij het spel!\n");
        console::print(
                "Als je het spel wilt genereren type `gen` anders voer hier het pad naam in van het bestand: \n");
        const auto path = console::get_input();

        if (path == "gen") {
            generate_locations();
        } else {
            const auto path2 = "/Users/devonthomassen/CLionProjects/kerkers-en-draken/resources/kasteelruine.xml";
            gameService_->start(path2);
//            gameService_->start(path.c_str());
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
        console::print("Voer een playernaam in: ");
        const auto playerName = get_input();
        player_ = std::make_unique<Player>(playerName);
    }

    void GameHandler::iterate() {
        player_->take_damage(gameService_->damage_of_the_round());
        if (player_->get_health() <= 0) {
            console::print("Je bent dood.\n");
            gameService_->exit();
            return;
        }
        print("Voer een commando in: ");
        const auto input = console::get_input();
        logger_->log(input.c_str());
        const auto [commandKey, arguments] = console::get_command_key(input);
        invoker_->invoke(commandKey, arguments);
    }

} // presentation
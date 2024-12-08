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
        const auto setup_status = set_start_up();
        if (setup_status != GAME_START_SUCCESS) {
            console::print("Er is iets fout gegaan bij het opzetten van het spel.\n");
            return;
        }
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

    int GameHandler::set_start_up() {
        console::print("Welkom bij het spel!\n");
        console::print(
                "Als je het spel wilt genereren type `gen` anders voer hier het pad naam in van het bestand: \n");
        const auto path = console::get_input();

        if (path == "gen") {
            return generate_locations();
        }
        const auto path2 = "/Users/devonthomassen/CLionProjects/kerkers-en-draken/resources/kasteelruine.xml";
        return gameService_->start(path2);
//        gameService_->start(path.c_str());
    }

    int GameHandler::generate_locations() {
        while (true) {
            console::print("Hoeveel locaties wil je genereren? (max 20) ");
            const auto amount = console::get_input_as_int();
            if (amount.has_value()) {
                const auto result = gameService_->start(amount.value());
                if (result != GAME_START_SUCCESS) {
                    console::print("Er is iets fout gegaan bij het genereren van de locaties.\n");
                    return GAME_START_FAILURE;
                }
                return GAME_START_SUCCESS;
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
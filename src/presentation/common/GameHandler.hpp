#ifndef GAMEHANDLER_HPP
#define GAMEHANDLER_HPP

#include <memory>
#include "GameService.hpp"
#include "commands/incl/CommandInvoker.hpp"
#include "common/Console.hpp"
#include "common/Player.hpp"

using namespace presentation::commands;

namespace presentation {

    class GameHandler final {
    public:
        explicit GameHandler();
        void start();

    private:
        std::shared_ptr<application::GameService> gameService_;
        std::unique_ptr<CommandInvoker> invoker_;
        std::unique_ptr<Player> player_;

        /**
         * @brief Iterates the game
         */
        void iterate();
    };
} // presentation

#endif //GAMEHANDLER_HPP

#ifndef GAMEHANDLER_HPP
#define GAMEHANDLER_HPP

#include <memory>
#include "GameService.hpp"
#include "commands/incl/CommandInvoker.hpp"
#include "common/Console.hpp"
#include "common/Player.hpp"
#include "../domain/logger/ILogger.hpp"

using namespace logger;
using namespace presentation::commands;

namespace presentation {
    /**
     * @class GameHandler
     * @brief Represents the game handler
     */
    class GameHandler final {
    public:
        explicit GameHandler(std::unique_ptr<ILogger> logger);

        /**
         * @brief Starts the game
         */
        void start();

    private:
        std::unique_ptr<ILogger> logger_;
        std::shared_ptr<application::GameService> gameService_;
        std::unique_ptr<CommandInvoker> invoker_;
        std::unique_ptr<Player> player_;

        /**
         * @brief Sets up the game
         */
        void set_start_up();

        /**
         * @brief Generates locations for the game
         */
        void generate_locations();

        /**
         * @brief Sets the player
         */
        void set_player();

        /**
         * @brief Iterates the game
         */
        void iterate();
    };
} // presentation

#endif //GAMEHANDLER_HPP

#ifndef CONSUMECOMMAND_HPP
#define CONSUMECOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using namespace application;

namespace presentation::commands {
    /**
     * @class ConsumeCommand
     * @brief Consumes an item in the player's inventory
     */
    class ConsumeCommand final : public ICommand {
    public:
        explicit ConsumeCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;

    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands

#endif //CONSUMECOMMAND_HPP

#ifndef TAKECOMMAND_HPP
#define TAKECOMMAND_HPP

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
     * @class TakeCommand
     * @brief Command for taking an item
     */
    class TakeCommand final : public ICommand {
    public:
        explicit TakeCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute() override;
    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands

#endif //TAKECOMMAND_HPP

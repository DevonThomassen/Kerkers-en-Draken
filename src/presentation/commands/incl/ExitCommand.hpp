#ifndef EXITCOMMAND_HPP
#define EXITCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

using namespace application;

namespace presentation::commands {

    /**
     * @class ExitCommand
     * @brief Command for exiting the game
     */
    class ExitCommand final : public ICommand {
    public:
        explicit ExitCommand(std::shared_ptr<GameService> game_service_);
        void execute() override;

    private:
        std::shared_ptr<GameService> game_service_;
    };
} // presentation::commands

#endif //EXITCOMMAND_HPP

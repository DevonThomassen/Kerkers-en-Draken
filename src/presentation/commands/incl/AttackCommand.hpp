#ifndef ATTACKCOMMAND_HPP
#define ATTACKCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using application::GameService;

namespace presentation::commands {

    /**
     * @class AttackCommand
     * @brief Command for attacking
     */
    class AttackCommand : public ICommand {
    public:
        explicit AttackCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;

    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;
    };
}

#endif //ATTACKCOMMAND_HPP

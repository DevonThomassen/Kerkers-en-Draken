#ifndef LOOKROOM_HPP
#define LOOKROOM_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using namespace application;

namespace presentation::commands {
    class LookRoomCommand final : public ICommand {
    public:
        explicit LookRoomCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;
    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands

#endif //LOOKROOM_HPP

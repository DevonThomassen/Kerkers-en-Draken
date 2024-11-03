#ifndef PUTOBJECTDOWNCOMMAND_HPP
#define PUTOBJECTDOWNCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using namespace application;

namespace presentation::commands {
    class PutObjectDownCommmand final : public ICommand {
    public:
        explicit PutObjectDownCommmand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute() override;
    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands

#endif //PUTOBJECTDOWNCOMMAND_HPP

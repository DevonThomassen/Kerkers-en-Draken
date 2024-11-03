#ifndef SEARCHCOMMAND_HPP
#define SEARCHCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using namespace application;

namespace presentation::commands {
    class SearchCommand final : public ICommand {
    public:
        explicit SearchCommand(std::shared_ptr<GameService> game_service);
        void execute(const std::string& arguments) override;
    private:
        std::shared_ptr<GameService> game_service_;
    };
} // presentation::commands

#endif //SEARCHCOMMAND_HPP

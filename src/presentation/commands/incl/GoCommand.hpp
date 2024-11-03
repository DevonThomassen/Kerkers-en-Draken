#ifndef GOCOMMAND_HPP
#define GOCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
}

using namespace application;

namespace presentation::commands {
    /**
     * @class GoCommand
     * @brief Command for going to the next location
     */
    class GoCommand final : public ICommand {
    public:
        explicit GoCommand(std::shared_ptr<GameService> game_service_);
        void execute() override;

    private:
        std::shared_ptr<GameService> game_service_;
    };
}

#endif //GOCOMMAND_HPP

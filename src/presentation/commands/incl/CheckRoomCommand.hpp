#ifndef CHECKROOMCOMMAND_HPP
#define CHECKROOMCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
}

using namespace application;

namespace presentation::commands {
    /**
     * @class CheckRoomCommand
     * @brief Command for checking the current room
     */
    class CheckRoomCommand final : public ICommand {
    public:
        explicit CheckRoomCommand(std::shared_ptr<GameService> game_service);
        void execute() override;

    private:
        std::shared_ptr<GameService> game_service_;
    };
}

#endif //CHECKROOMCOMMAND_HPP

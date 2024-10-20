#ifndef CHECKROOMCOMMAND_HPP
#define CHECKROOMCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation::commands {

    /**
     * @class CheckRoomCommand
     * @brief Command for checking the current room
     */
    class CheckRoomCommand final : public ICommand {
    public:
        void execute() override;
    };
}

#endif //CHECKROOMCOMMAND_HPP

#ifndef UNKNOWNCOMMAND_HPP
#define UNKNOWNCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation::commands {

    /**
     * @class UnknownCommand
     * @brief Command for unknown commands
     */
    class UnknownCommand final : public ICommand {
    public:
        void execute() override;
    };
}
#endif //UNKNOWNCOMMAND_HPP

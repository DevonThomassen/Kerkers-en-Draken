#ifndef ATTACKCOMMAND_HPP
#define ATTACKCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation::commands {

    /**
     * @class AttackCommand
     * @brief Command for attacking
     */
    class AttackCommand : public ICommand {
    public:
        void execute() override;
    };
}

#endif //ATTACKCOMMAND_HPP

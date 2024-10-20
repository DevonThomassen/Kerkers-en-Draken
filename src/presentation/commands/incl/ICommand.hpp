#ifndef ICOMMAND_HPP
#define ICOMMAND_HPP

#include <iostream>

namespace presentation::commands {

    /**
     * @class ICommand
     * @brief Interface for command pattern
     */
    class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual void execute() = 0;
    };

}

#endif //ICOMMAND_HPP

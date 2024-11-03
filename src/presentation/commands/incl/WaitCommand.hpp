#ifndef WAITCOMMAND_HPP
#define WAITCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation::commands {
    /**
     * @class WaitCommand
     * @brief Command for waiting
     */
    class WaitCommand : public ICommand {
    public:
        explicit WaitCommand();
        void execute(const std::string& arguments) override;
    };
}
#endif //WAITCOMMAND_HPP

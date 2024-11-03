#ifndef HELPCOMMAND_HPP
#define HELPCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation::commands {

    /**
     * @class HelpCommand
     * @brief Command for displaying help
     */
    class HelpCommand final : public ICommand {
    public:
        void execute(const std::string& arguments) override;
    };
}

#endif //HELPCOMMAND_HPP

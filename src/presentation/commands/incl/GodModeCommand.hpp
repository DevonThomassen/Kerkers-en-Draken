#ifndef GODMODECOMMAND_HPP
#define GODMODECOMMAND_HPP

#include "ICommand.hpp"

namespace presentation {
    class Player;
} // presentation

namespace presentation::commands {
    /**
     * @class GoCommand
     * @brief Command for going to the next location
     */
    class GodModeCommand final : public ICommand {
    public:
        explicit GodModeCommand(std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;

    private:
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands

#endif //GODMODECOMMAND_HPP

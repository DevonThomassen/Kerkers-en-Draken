#ifndef GODMODECOMMAND_HPP
#define GODMODECOMMAND_HPP

#include "ICommand.hpp"

namespace presentation {
    class Player;
} // presentation

namespace presentation::commands {
    /**
     * @class GodModeCommand
     * @brief Command for enabling god mode
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

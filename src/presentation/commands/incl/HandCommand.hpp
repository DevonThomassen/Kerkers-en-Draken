#ifndef HANDCOMMAND_HPP
#define HANDCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation {
    class Player;
} // presentation

namespace presentation::commands {
    /**
     * @class HandCommand
     * @brief Command for showing the player's hand
     */
    class HandCommand final : public ICommand {
    public:
        explicit HandCommand(std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;
    private:
        std::unique_ptr<Player>& player_;
    };
} // presentation::commands
#endif //HANDCOMMAND_HPP

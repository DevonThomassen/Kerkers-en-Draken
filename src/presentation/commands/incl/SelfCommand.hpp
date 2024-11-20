#ifndef SELFCOMMAND_HPP
#define SELFCOMMAND_HPP

#include "ICommand.hpp"

namespace presentation {
    class Player;
} // presentation

namespace presentation::commands {
    /**
     * @class SelfCommand
     * @brief Represents the command to show the player's information
     */
    class SelfCommand final : public ICommand {
    public:
        explicit SelfCommand(const std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;

    private:
        const std::unique_ptr<Player>& player_;
    };

} // presentation::commands

#endif //SELFCOMMAND_HPP

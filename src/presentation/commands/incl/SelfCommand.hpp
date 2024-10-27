#ifndef SELFCOMMAND_HPP
#define SELFCOMMAND_HPP

#include "ICommand.hpp"
#include "../../common/Console.hpp"
#include "../../common/Player.hpp"

namespace presentation::commands {

    class SelfCommand final : ICommand {
    public:
        explicit SelfCommand(std::unique_ptr<Player>& player);
        void execute() override;

    private:
        std::unique_ptr<Player>& player_;
    };

} // presentation::commands

#endif //SELFCOMMAND_HPP

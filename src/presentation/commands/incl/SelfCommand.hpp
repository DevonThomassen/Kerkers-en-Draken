#ifndef SELFCOMMAND_HPP
#define SELFCOMMAND_HPP

#include "ICommand.hpp"
#include "../../common/Console.hpp"
#include "../../common/Player.hpp"

namespace presentation::commands {

    class SelfCommand final : public ICommand {
    public:
        explicit SelfCommand(const std::unique_ptr<Player>& player);
        void execute() override;

    private:
        const std::unique_ptr<Player>& player_;
    };

} // presentation::commands

#endif //SELFCOMMAND_HPP

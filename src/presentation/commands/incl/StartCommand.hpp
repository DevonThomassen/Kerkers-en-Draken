#ifndef STARTCOMMAND_HPP
#define STARTCOMMAND_HPP

#include "ICommand.hpp"
#include <string>

namespace application {
    class GameService;
} // application

using namespace application;

namespace presentation::commands {

    class StartCommand : public ICommand {
    public:
        explicit StartCommand(std::shared_ptr<GameService> gameService);
        ~StartCommand() override = default;

        void execute(const std::string& arguments) override;

    private:
        std::shared_ptr<GameService> gameService_;
        std::string default_path;
    };

} // presentation::commands

#endif //STARTCOMMAND_HPP

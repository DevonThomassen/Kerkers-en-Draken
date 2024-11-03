#ifndef COMMANDINVOKER_HPP
#define COMMANDINVOKER_HPP

#include <unordered_map>
#include "ICommand.hpp"
#include "commands/CommandKey.h"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

namespace presentation::commands {
    /**
     * @class CommandInvoker
     * @brief Invokes commands
     */
    class CommandInvoker {
    public:
        explicit CommandInvoker(std::unique_ptr<Player>& player, const std::shared_ptr<application::GameService>& gameService);
        void invoke(const CommandKey& key);

    private:
        std::unique_ptr<Player>& player_;
        const std::shared_ptr<application::GameService>& gameService_;
        std::unordered_map<CommandKey, std::unique_ptr<ICommand>> commands_;
    };
}

#endif //COMMANDINVOKER_HPP

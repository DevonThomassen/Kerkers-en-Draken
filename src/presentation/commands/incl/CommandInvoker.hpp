#ifndef COMMANDINVOKER_HPP
#define COMMANDINVOKER_HPP

#include <unordered_map>
#include "ICommand.hpp"
#include "commands/CommandKey.h"
#include "../../../application/GameService.hpp"

namespace presentation::commands {

    /**
     * @class CommandInvoker
     * @brief Invokes commands
     */
    class CommandInvoker {
    public:
        explicit CommandInvoker(const std::shared_ptr<application::GameService>& gameService);
        void invoke(const CommandKey& key);

    private:
        const std::shared_ptr<application::GameService>& gameService_;
        std::unordered_map<CommandKey, std::unique_ptr<ICommand>> commands_;
    };
}

#endif //COMMANDINVOKER_HPP

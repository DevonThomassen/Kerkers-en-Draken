#include "../incl/CommandInvoker.hpp"
#include "../incl/HelpCommand.hpp"
#include "../incl/UnknownCommand.hpp"
#include "../incl/AttackCommand.hpp"
#include "../incl/CheckRoomCommand.hpp"
#include "../incl/ExitCommand.hpp"
#include "commands/incl/StartCommand.hpp"

namespace presentation::commands {

    CommandInvoker::CommandInvoker(const std::unique_ptr<Player>& player,
                                   const std::shared_ptr<application::GameService>& gameService)
            : player_(player),
              gameService_(gameService) {
        commands_[CommandKey::START] = std::make_unique<StartCommand>(gameService_);
        commands_[CommandKey::ATTACK] = std::make_unique<AttackCommand>();
        commands_[CommandKey::SEARCH] = std::make_unique<CheckRoomCommand>();
        commands_[CommandKey::EXIT] = std::make_unique<ExitCommand>(gameService_);
        commands_[CommandKey::UNKNOWN] = std::make_unique<UnknownCommand>();
        commands_[CommandKey::HELP] = std::make_unique<HelpCommand>();
    }

    void CommandInvoker::invoke(const CommandKey& key) {
        if (commands_.contains(key)) {
            commands_[key]->execute();
        } else {
            commands_[CommandKey::UNKNOWN]->execute();
        }
    }

} // presentation::commands

#include "commands/incl/CommandInvoker.hpp"

#include "../../../application/GameService.hpp"
#include "common/Player.hpp"

#include "commands/incl/HelpCommand.hpp"
#include "commands/incl/UnknownCommand.hpp"
#include "commands/incl/AttackCommand.hpp"
#include "commands/incl/CheckRoomCommand.hpp"
#include "commands/incl/ExitCommand.hpp"
#include "commands/incl/SelfCommand.hpp"
#include "commands/incl/GoCommand.hpp"
#include "commands/incl/StartCommand.hpp"

namespace presentation::commands {

    CommandInvoker::CommandInvoker(const std::unique_ptr<Player>& player,
                                   const std::shared_ptr<application::GameService>& gameService)
            : player_(player),
              gameService_(gameService) {
        commands_[CommandKey::START] = std::make_unique<StartCommand>(gameService_);
        commands_[CommandKey::ATTACK] = std::make_unique<AttackCommand>();
        commands_[CommandKey::LOOK] = std::make_unique<CheckRoomCommand>(gameService_);
        commands_[CommandKey::EXIT] = std::make_unique<ExitCommand>(gameService_);
        commands_[CommandKey::UNKNOWN] = std::make_unique<UnknownCommand>();
        commands_[CommandKey::HELP] = std::make_unique<HelpCommand>();
        commands_[CommandKey::SELF] = std::make_unique<SelfCommand>(player_);
        commands_[CommandKey::GO] = std::make_unique<GoCommand>(gameService_);
    }

    void CommandInvoker::invoke(const CommandKey& key) {
        if (commands_.contains(key)) {
            commands_[key]->execute();
        } else {
            commands_[CommandKey::UNKNOWN]->execute();
        }
    }

} // presentation::commands

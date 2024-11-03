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
#include "commands/incl/TakeCommand.hpp"
#include "commands/incl/LookRoomCommand.hpp"
#include "commands/incl/SearchCommand.hpp"
#include "commands/incl/PutObjectDownCommand.hpp"

namespace presentation::commands {

    CommandInvoker::CommandInvoker(std::unique_ptr<Player>& player,
                                   const std::shared_ptr<application::GameService>& gameService)
            : player_(player),
              gameService_(gameService) {
        commands_[CommandKey::START] = std::make_unique<StartCommand>(gameService_);
        commands_[CommandKey::ATTACK] = std::make_unique<AttackCommand>();
        commands_[CommandKey::LOOK] = std::make_unique<LookRoomCommand>(gameService_, player_);
        commands_[CommandKey::EXIT] = std::make_unique<ExitCommand>(gameService_);
        commands_[CommandKey::UNKNOWN] = std::make_unique<UnknownCommand>();
        commands_[CommandKey::HELP] = std::make_unique<HelpCommand>();
        commands_[CommandKey::SELF] = std::make_unique<SelfCommand>(player_);
        commands_[CommandKey::GO] = std::make_unique<GoCommand>(gameService_);
        commands_[CommandKey::TAKE] = std::make_unique<TakeCommand>(gameService_, player_);
        commands_[CommandKey::SEARCH] = std::make_unique<SearchCommand>(gameService_);
        commands_[CommandKey::PUT] = std::make_unique<PutObjectDownCommmand>(gameService_, player_);
    }

    void CommandInvoker::invoke(const CommandKey& key, const std::string& arguments) {
        if (commands_.contains(key)) {
            commands_[key]->execute(arguments);
        } else {
            commands_[CommandKey::UNKNOWN]->execute(arguments);
        }
    }

} // presentation::commands

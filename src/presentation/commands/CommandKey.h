#ifndef COMMANDKEY_H
#define COMMANDKEY_H

#include <vector>
#include <iostream>

/**
 * @namespace presentation::commands
 * @brief Contains functionality for commands
 */
namespace presentation::commands {

    /**
     * @enum CommandKey
     * @brief Enum for command keys
     */
    enum class CommandKey {
        UNKNOWN,
        HELP,
        START,
        LOOK,
        SEARCH,
        TAKE,
        ATTACK,
        EXIT,
        GO,
        PUT,
        CONSUME,
        WAIT,
        HAND,
        GOD_MODE
    };

    /**
     * @struct CommandKeyAndArguments
     * @brief Struct for command key and arguments
     */
    struct CommandKeyAndArguments {
        CommandKey key;
        std::string arguments;
    };

}

#endif //COMMANDKEY_H

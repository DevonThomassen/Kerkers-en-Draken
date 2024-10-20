#ifndef COMMANDKEY_H
#define COMMANDKEY_H

#include <vector>
#include <iostream>

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
        EXIT
    };

    struct CommandKeyAndArguments {
        CommandKey key;
        std::vector<std::string> arguments;
    };

}

#endif //COMMANDKEY_H

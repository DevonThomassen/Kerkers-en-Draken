#ifndef LOOKCOMMAND_HPP
#define LOOKCOMMAND_HPP

#include "ICommand.hpp"

namespace application {
    class GameService;
} // application

namespace presentation {
    class Player;
} // presentation

using namespace application;

namespace presentation::commands {
    class LookCommand final : public ICommand {
    public:
        explicit LookCommand(std::shared_ptr<GameService> game_service, std::unique_ptr<Player>& player);
        void execute(const std::string& arguments) override;
    private:
        std::shared_ptr<GameService> game_service_;
        std::unique_ptr<Player>& player_;

        /**
         * @brief Look at the room.
         */
        void look_room();

        void look_self();
        /**
         * @brief Look at a specific item in the room.
         * @param name The name of the item to look at.
         * @return True if the item was found, false otherwise.
         */
        bool look_item(const std::string& name);
        /**
         * @brief Look if there is an enemy in the room.
         * @param name The name of the enemy to look for.
         * @return True if there is an enemy in the room, false otherwise.
         */
        bool look_enemy(const std::string& name);
    };
} // presentation::commands

#endif //LOOKCOMMAND_HPP

#ifndef DATABASEREPOSITORY_HPP
#define DATABASEREPOSITORY_HPP

#define DEFAULT_DB_PATH "/Users/devonthomassen/CLionProjects/kerkers-en-draken/resources/kerkersendraken.db"

namespace domain {
    struct Leaderboard;
    struct LeaderboardRow;
} // domain

namespace game_objects {
    class EnemyObject;
    class GameObject;
} // game_objects

/**
 * @namespace database
 * @brief Contains functionality for the database
 */
namespace database {
    /**
     * @class DatabaseRepository
     * @brief Base class for all repositories
     */
    class DatabaseRepository {
    public:
        explicit DatabaseRepository() = delete;
        virtual ~DatabaseRepository() = delete;

        /**
         * @brief Opens the database
         * @return 0 if successful, -1 if not
         */
        static int open();
        /**
         * @brief Closes the database
         * @return 0 if successful, -1 if not
         */
        static int close();

        /**
         * @brief Gets an enemy from the database
         * @param name The name of the enemy
         * @return The enemy or a nullptr
         */
        [[nodiscard]] static game_objects::EnemyObject* get_enemy(const char* name);
        /**
         * @brief Gets an item from the database
         * @param name The name of the item
         * @param invisible A boolean that represents if the item is invisible
         * @return The item or a nullptr
         */
        [[nodiscard]] static game_objects::GameObject* get_item(const char* name, bool invisible = false);
        /**
         * @brief Gets the leaderboard from the database
         * @return The leaderboard or a nullptr
         */
        [[nodiscard]] static domain::Leaderboard* get_leaderboard();
        /**
         * @brief Gets a leaderboard row from the database
         * @param name The name of the player
         * @return The leaderboard row or a nullptr
         */
        [[nodiscard]] static domain::LeaderboardRow* get_leaderboard_row(const char* name);
        static void create_leaderboard_row();
    };
} // database

#endif //DATABASEREPOSITORY_HPP

#ifndef DATABASEREPOSITORY_HPP
#define DATABASEREPOSITORY_HPP

#define DEFAULT_DB_PATH "/Users/devonthomassen/CLionProjects/kerkers-en-draken/resources/kerkersendraken.db"

namespace game_objects {
    class EnemyObject;
    class GameObject;
}

namespace database {
    /**
     * @class DatabaseRepository
     * @brief Base class for all repositories
     */
    class DatabaseRepository {
    public:
        explicit DatabaseRepository() = delete;
        virtual ~DatabaseRepository() = delete;

        [[nodiscard]] static game_objects::EnemyObject* get_enemy(const char* name);
        [[nodiscard]] static game_objects::GameObject* get_item(const char* name);

        static int open();
        static int close();
    };
} // database

#endif //DATABASEREPOSITORY_HPP

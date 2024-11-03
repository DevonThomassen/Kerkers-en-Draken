#ifndef BASEREPOSITORY_HPP
#define BASEREPOSITORY_HPP

#define DEFAULT_DB_PATH "/Users/devonthomassen/CLionProjects/kerkers-en-draken/resources/kerkersendraken.db"

namespace game_objects {
    class EnemyObject;

    class GameObject;
}

namespace repository {
    /**
     * @class BaseRepository
     * @brief Base class for all repositories
     */
    class BaseRepository {
    public:
        explicit BaseRepository() = delete;
        virtual ~BaseRepository() = delete;

        [[nodiscard]] static game_objects::EnemyObject* get_enemy(const char* name);
        [[nodiscard]] static game_objects::GameObject* get_item(const char* name);

        static int open();
        static int close();
    };
}

#endif //BASEREPOSITORY_HPP

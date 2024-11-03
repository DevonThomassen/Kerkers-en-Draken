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
        explicit BaseRepository();
        virtual ~BaseRepository();

        [[nodiscard]] game_objects::EnemyObject* get_enemy(const char* name);
        [[nodiscard]] game_objects::GameObject* get_item(const char* name);

        static int open();
//        [[maybe_unused]] static int close();
    };
}

#endif //BASEREPOSITORY_HPP

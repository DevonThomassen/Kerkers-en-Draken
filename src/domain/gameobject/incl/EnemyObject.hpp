#ifndef ENEMYOBJECT_HPP
#define ENEMYOBJECT_HPP

#include "GameObject.hpp"

namespace game_objects {
    /**
     * @class EnemyObject
     * @brief A class that represents an enemy object in the game.
     */
    class EnemyObject final : public GameObject {
    public:
        explicit EnemyObject(int health, const char* name, const char* description);
        EnemyObject(const EnemyObject& other);
        EnemyObject(EnemyObject&& other) noexcept;
        EnemyObject& operator=(const EnemyObject& other);
        EnemyObject& operator=(EnemyObject&& other) noexcept;
        ~EnemyObject() override;

    private:
        int health_;
    };
}

#endif //ENEMYOBJECT_HPP

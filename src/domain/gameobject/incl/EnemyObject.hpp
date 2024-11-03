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
        explicit EnemyObject(int health, int attack_chance, int damage, const char* name, const char* description);
        EnemyObject(const EnemyObject& other);
        EnemyObject(EnemyObject&& other) noexcept;
        EnemyObject& operator=(const EnemyObject& other);
        EnemyObject& operator=(EnemyObject&& other) noexcept;
        ~EnemyObject() override;

        [[nodiscard]] int get_health() const;
        [[nodiscard]] int get_attack_chance() const;
        [[nodiscard]] int get_damage() const;
        void take_damage(int damage);

    private:
        int health_;
        int attack_chance_;
        int damage_;
    };
}

#endif //ENEMYOBJECT_HPP

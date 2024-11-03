#include "../incl/EnemyObject.hpp"

namespace game_objects {

    EnemyObject::EnemyObject(const int health,
                             const int attack_chance,
                             const int damage,
                             const char* name,
                             const char* description)
            : health_(health),
              attack_chance_(attack_chance),
              damage_(damage),
              GameObject(name, description) {}

    EnemyObject::EnemyObject(const EnemyObject& other) = default;
    EnemyObject::EnemyObject(EnemyObject&& other) noexcept = default;
    EnemyObject& EnemyObject::operator=(const EnemyObject& other) = default;
    EnemyObject& EnemyObject::operator=(EnemyObject&& other) noexcept = default;
    EnemyObject::~EnemyObject() = default;
}

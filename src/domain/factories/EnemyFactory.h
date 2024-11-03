#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <cstdio>

#include "../../domain/gameobject/incl/EnemyObject.hpp"

using namespace game_objects;

namespace factories {
    /**
     * @var enemy_count_
     * @brief A static variable that represents the unique identifier for each enemy object.
     */
    static int enemy_count_ = 0;

    /**
     * @struct EnemyFactory
     * @brief A class that represents a factory for creating enemy objects.
     */
    struct EnemyFactory {
        /**
         * @brief Creates an EnemyObject with the given name and description.
         * @param health The health of the enemy.
         * @param name The name of the enemy.
         * @param description The description of the enemy.
         * @return An EnemyObject with the given name and description.
         */
        static EnemyObject*
        create(int health, int attack_chance, int damage, const char* name, const char* description) {
            char full_name[256];
            snprintf(full_name, sizeof(full_name), "%s %d", name, ++enemy_count_);
            return new EnemyObject(health, attack_chance, damage, full_name, description);
        }
    };
} // factories

#endif //ENEMYFACTORY_H

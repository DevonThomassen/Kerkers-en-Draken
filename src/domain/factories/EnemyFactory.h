#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "../gameobject/incl/EnemyObject.hpp"

using namespace game_objects;

namespace factories {
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
        static EnemyObject* create(int health, const char* name, const char* description) {
            return new EnemyObject(health, name, description);
        }
    };
} // factories

#endif //ENEMYFACTORY_H

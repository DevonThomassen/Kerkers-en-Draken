#ifndef COMMON_H
#define COMMON_H

namespace common {

    /**
     * @enum GameObjectType
     * @brief Represents the type of a game object for the database
     */
    enum class GameObjectType {
        BASE = 0,
        ARMOUR = 1,
        CONSUMABLE = 2,
        GOLD = 3,
        WEAPON = 4,
        ENEMY = 5
    };

}

#endif //COMMON_H

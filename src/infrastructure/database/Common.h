#ifndef COMMON_H
#define COMMON_H

#include <cstring>

/**
 * @namespace infrastructure::common
 * @brief Contains common classes and functions for the infrastructure layer
 */
namespace infrastructure::common {
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

    GameObjectType static convert_to_game_object_type(const char* type) {
        if (strcmp(type, "wapenrusting") == 0) {
            return GameObjectType::ARMOUR;
        }
        if (strcmp(type, "levenselixer") == 0
            or strcmp(type, "ervaringsdrank") == 0
            or strcmp(type, "teleportatiedrank") == 0) {
            return GameObjectType::CONSUMABLE;
        }
        if (strcmp(type, "wapen") == 0) {
            return GameObjectType::WEAPON;
        }
        if (strcmp(type, "goudstukken") == 0) {
            return GameObjectType::GOLD;
        }
        return GameObjectType::BASE;
    }

}

#endif //COMMON_H

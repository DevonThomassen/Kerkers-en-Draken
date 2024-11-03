#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "../gameobject/incl/GameObject.hpp"

using namespace game_objects;

namespace factories {
    /**
     * @var object_count_
     * @brief A static variable that represents the unique identifier for each game object.
     */
    static int object_count_ = 0;

    /**
     * @struct GameObjectFactory
     * @brief A struct that represents a factory for creating game objects.
     */
    struct GameObjectFactory {
        /**
         * @brief Creates a GameObject with the given name and description.
         * @param type The type of the game object.
         * @param name The name of the game object.
         * @param description The description of the game object.
         * @param value The value of the game object.
         * @param invisible A boolean that represents if the game object is invisible.
         * @return A GameObject with the given name and description.
         */
        static GameObject* create(const char* type, const char* name, const char* description, int value, bool invisible = false);
    };
} // factories

#endif //GAMEOBJECTFACTORY_H

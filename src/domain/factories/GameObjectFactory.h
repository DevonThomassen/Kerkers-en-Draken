#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "../gameobject/incl/GameObject.hpp"

using namespace game_objects;

namespace factories {

    /**
     * @struct GameObjectFactory
     * @brief A struct that represents a factory for creating game objects.
     */
    struct GameObjectFactory {
        /**
         * @brief Creates a GameObject with the given name and description.
         * @param name The name of the game object.
         * @param description The description of the game object.
         * @return A GameObject with the given name and description.
         */
        static GameObject* create(const char* name, const char* description) {
            return new GameObject(name, description);
        }
    };
}

#endif //GAMEOBJECTFACTORY_H

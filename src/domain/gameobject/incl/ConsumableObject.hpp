#ifndef CONSUMABLEOBJECT_HPP
#define CONSUMABLEOBJECT_HPP

#include "GameObject.hpp"

namespace game_objects {
    /**
     * @class ConsumableObject
     * @brief A class that represents a consumable object in the game.
     */
    class ConsumableObject final : public GameObject {
    public:
        explicit ConsumableObject(const char* name, const char* description, int value, bool invisible = false);
        ConsumableObject(const ConsumableObject& other);
        ConsumableObject(ConsumableObject&& other) noexcept;
        ConsumableObject& operator=(const ConsumableObject& other);
        ConsumableObject& operator=(ConsumableObject&& other) noexcept;
        ~ConsumableObject() override = default;

    private:
        int value_;
    };
}

#endif //CONSUMABLEOBJECT_HPP

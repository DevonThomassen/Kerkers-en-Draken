#include "../incl/ConsumableObject.hpp"

namespace game_objects {

    ConsumableObject::ConsumableObject(const char* name, const char* description)
            : GameObject(name, description) {}

    ConsumableObject::ConsumableObject(const ConsumableObject& other) = default;
    ConsumableObject::ConsumableObject(ConsumableObject&& other) noexcept = default;
    ConsumableObject& ConsumableObject::operator=(const ConsumableObject& other) = default;
    ConsumableObject& ConsumableObject::operator=(ConsumableObject&& other) noexcept = default;

}


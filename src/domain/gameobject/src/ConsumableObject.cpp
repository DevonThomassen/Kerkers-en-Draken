#include "../incl/ConsumableObject.hpp"

namespace game_objects {

    ConsumableObject::ConsumableObject(const char* name, const char* description, const int value, const bool invisible)
            : GameObject(name, description, invisible),
              value_(value) {}

    ConsumableObject::ConsumableObject(const ConsumableObject& other) = default;
    ConsumableObject::ConsumableObject(ConsumableObject&& other) noexcept = default;
    ConsumableObject& ConsumableObject::operator=(const ConsumableObject& other) = default;
    ConsumableObject& ConsumableObject::operator=(ConsumableObject&& other) noexcept = default;

}


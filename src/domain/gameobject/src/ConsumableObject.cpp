#include "../incl/ConsumableObject.hpp"

namespace game_objects {

    ConsumableObject::ConsumableObject(const char* name, const char* description, const int value, const char* type, const bool invisible)
            : GameObject(name, description, invisible),
              type_(type), value_(value) {}

    const char* ConsumableObject::get_type() const {
        return type_;
    }

    int ConsumableObject::get_value() const {
        return value_;
    }

    ConsumableObject::ConsumableObject(const ConsumableObject& other) = default;
    ConsumableObject::ConsumableObject(ConsumableObject&& other) noexcept = default;
    ConsumableObject& ConsumableObject::operator=(const ConsumableObject& other) = default;
    ConsumableObject& ConsumableObject::operator=(ConsumableObject&& other) noexcept = default;

}


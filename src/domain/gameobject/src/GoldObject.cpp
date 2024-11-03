#include "../incl/GoldObject.hpp"

namespace game_objects {

    GoldObject::GoldObject(const char* name, const char* description, const int amount)
            : amount_(amount),
              GameObject(name, description) {}

    GoldObject::GoldObject(const GoldObject& other) = default;
    GoldObject::GoldObject(GoldObject&& other) noexcept = default;
    GoldObject& GoldObject::operator=(const GoldObject& other) = default;
    GoldObject& GoldObject::operator=(GoldObject&& other) noexcept = default;

    int GoldObject::get_amount() const {
        return amount_;
    }
}

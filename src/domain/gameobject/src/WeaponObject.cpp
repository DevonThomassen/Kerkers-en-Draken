#include "../incl/WeaponObject.hpp"

namespace game_objects {

    WeaponObject::WeaponObject(const char* name, const char* description, const int damage, const bool invisible)
            : GameObject(name, description, invisible),
              damage_(damage) {}

    WeaponObject::WeaponObject(const WeaponObject& other) = default;
    WeaponObject::WeaponObject(WeaponObject&& other) noexcept = default;
    WeaponObject& WeaponObject::operator=(const WeaponObject& other) = default;
    WeaponObject& WeaponObject::operator=(WeaponObject&& other) noexcept = default;
    WeaponObject::~WeaponObject() = default;
}

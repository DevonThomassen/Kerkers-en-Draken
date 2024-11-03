#include "../incl/WeaponObject.hpp"

namespace game_objects {

    WeaponObject::WeaponObject(const char* name, const char* description, const int damage)
            : damage_(damage),
              GameObject(name, description) {}

    WeaponObject::WeaponObject(const WeaponObject& other) = default;
    WeaponObject::WeaponObject(WeaponObject&& other) noexcept = default;
    WeaponObject& WeaponObject::operator=(const WeaponObject& other) = default;
    WeaponObject& WeaponObject::operator=(WeaponObject&& other) noexcept = default;
    WeaponObject::~WeaponObject() = default;
}

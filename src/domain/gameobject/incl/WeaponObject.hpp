#ifndef WEAPONOBJECT_HPP
#define WEAPONOBJECT_HPP

#include "GameObject.hpp"

namespace game_objects {
    /**
     * @class WeaponObject
     * @brief A class that represents a weapon object in the game.
     */
    class WeaponObject final : public GameObject {
    public:
        explicit WeaponObject(const char* name, const char* description);
        WeaponObject(const WeaponObject& other);
        WeaponObject(WeaponObject&& other) noexcept;
        WeaponObject& operator=(const WeaponObject& other);
        WeaponObject& operator=(WeaponObject&& other) noexcept;
        ~WeaponObject() override;
    };
}

#endif //WEAPONOBJECT_HPP

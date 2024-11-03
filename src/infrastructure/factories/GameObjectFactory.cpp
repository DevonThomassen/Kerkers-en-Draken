#include "../../domain/factories/GameObjectFactory.h"

#include <cstdio>

#include "../../domain/gameobject/incl/ArmourObject.hpp"
#include "../../domain/gameobject/incl/WeaponObject.hpp"
#include "../../domain/gameobject/incl/ConsumableObject.hpp"
#include "../../domain/gameobject/incl/GoldObject.hpp"

#include "../database/Common.h"

namespace factories {

    GameObject*
    factories::GameObjectFactory::create(const char* type, const char* name, const char* description, int value) {
        char full_name[256];
        snprintf(full_name, sizeof(full_name), "%s %d", name, ++object_count_);
        const auto type_enum = common::convert_to_game_object_type(type);
        switch (type_enum) {
            case common::GameObjectType::ARMOUR:
                return new game_objects::ArmourObject(full_name, description, value);
            case common::GameObjectType::WEAPON:
                return new game_objects::WeaponObject(full_name, description, value);
            case common::GameObjectType::CONSUMABLE:
                return new game_objects::ConsumableObject(full_name, description, value);
            case common::GameObjectType::GOLD:
                return new game_objects::GoldObject(full_name, description, value);
            case common::GameObjectType::BASE:
            default:
                return nullptr;
        }
    }
} // factories
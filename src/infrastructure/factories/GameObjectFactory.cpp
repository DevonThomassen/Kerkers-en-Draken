
#include "../../domain/factories/GameObjectFactory.h"
#include "../../domain/gameobject/incl/ArmourObject.hpp"
#include "../../domain/gameobject/incl/WeaponObject.hpp"
#include "../../domain/gameobject/incl/ConsumableObject.hpp"
#include "../../domain/gameobject/incl/GoldObject.hpp"

#include "../database/Common.h"

namespace factories {

    GameObject*
    factories::GameObjectFactory::create(const char* type, const char* name, const char* description, int value) {
        const auto type_enum = common::convert_to_game_object_type(type);
        switch (type_enum) {
            case common::GameObjectType::ARMOUR:
                return new game_objects::ArmourObject(name, description, value);
            case common::GameObjectType::WEAPON:
                return new game_objects::WeaponObject(name, description, value);
            case common::GameObjectType::CONSUMABLE:
                return new game_objects::ConsumableObject(name, description, value);
            case common::GameObjectType::GOLD:
                return new game_objects::GoldObject(name, description, value);
            case common::GameObjectType::BASE:
            default:
                return nullptr;
        }
    }
} // factories
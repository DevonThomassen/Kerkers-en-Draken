#include "../../domain/factories/GameObjectFactory.h"

#include <cstdio>

#include "../../domain/gameobject/incl/ArmourObject.hpp"
#include "../../domain/gameobject/incl/WeaponObject.hpp"
#include "../../domain/gameobject/incl/ConsumableObject.hpp"
#include "../../domain/gameobject/incl/GoldObject.hpp"

#include "../database/Common.h"

using namespace infrastructure::common;

namespace factories {

    GameObject*
    factories::GameObjectFactory::create(const char* type, const char* name, const char* description, int value,
                                         bool invisible) {
        char* full_name = new char[strlen(name) + 12];
        snprintf(full_name, strlen(name) + 12, "%s %d", name, ++object_count_);
        const auto type_enum = convert_to_game_object_type(type);
        switch (type_enum) {
            case GameObjectType::ARMOUR:
                return new game_objects::ArmourObject(full_name, description, value, invisible);
            case GameObjectType::WEAPON:
                return new game_objects::WeaponObject(full_name, description, value, invisible);
            case GameObjectType::CONSUMABLE:
                return new game_objects::ConsumableObject(full_name, description, value, type, invisible);
            case GameObjectType::GOLD:
                return new game_objects::GoldObject(full_name, description, value, invisible);
            case GameObjectType::BASE:
            default:
                delete[] full_name;
                return nullptr;
        }
    }
} // factories
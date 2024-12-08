#include "../../domain/factories/EnemyFactory.h"
#include "../../domain/gameobject/incl/EnemyObject.hpp"

#include <cstdio>
#include <cstring>

using namespace game_objects;

namespace factories {
    EnemyObject*
    EnemyFactory::create(int health, int attack_chance, int damage, const char* name, const char* description) {
        char* full_name = new char[strlen(name) + 12];
        snprintf(full_name, strlen(name) + 12, "%s %d", name, ++enemy_count_);
        return new EnemyObject(health, attack_chance, damage, full_name, description);
    }
} // factories

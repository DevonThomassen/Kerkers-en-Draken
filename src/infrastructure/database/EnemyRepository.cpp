#include "../../domain/database/EnemyRepository.hpp"
#include "Common.h"
#include <iostream>

constexpr const auto ENEMY_TYPE = common::GameObjectType::ENEMY;

namespace constants {
    static constexpr const auto TABLE_NAME = "Vijanden";
    static constexpr const auto COL_NAME = "naam";
    static constexpr const auto COL_DESCRIPTION = "omschrijving";
    static constexpr const auto COL_MIN_OBJ = "minimumobjecten";
    static constexpr const auto COL_MAX_OBJ = "maximumobjecten";
    static constexpr const auto COL_HEALTH = "levenspunten";
    static constexpr const auto COL_ATTACK_CHANCE = "aanvalskans";
    static constexpr const auto COL_MIN_DAMAGE = "minimumschade";
    static constexpr const auto COL_MAX_DAMAGE = "maximumschade";

}

repository::EnemyRepository::EnemyRepository() {
}

game_objects::EnemyObject* repository::EnemyRepository::get_enemy(int id) {
    return nullptr;
}

game_objects::EnemyObject* repository::EnemyRepository::get_enemy(const char* name) {
//    sqlite3_stmt* stmt = nullptr;
//    if (sqlite3_prepare_v2(db_, constants::ENEMY_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
//        std::cerr << sqlite3_errmsg(db_) << std::endl;
//        return nullptr;
//    }
//    if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
//        return nullptr;
//    }
//
//    while (sqlite3_step(stmt) == SQLITE_ROW) {
//        const auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
//        const auto description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
//        const auto min_obj = sqlite3_column_int(stmt, 2);
//        const auto max_obj = sqlite3_column_int(stmt, 3);
//        const auto health = sqlite3_column_int(stmt, 4);
//        const auto attack_chance = sqlite3_column_int(stmt, 5);
//        const auto min_damage = sqlite3_column_int(stmt, 6);
//        const auto max_damage = sqlite3_column_int(stmt, 7);
//
//        return new game_objects::EnemyObject(health, name, description);
//    }

    return nullptr;
}

#include "../../domain/database/BaseRepository.hpp"

#include "../../domain/gameobject/incl/EnemyObject.hpp"

#include <sqlite3.h>
#include <iostream>

namespace repository {

    static sqlite3* db_ = nullptr;

    namespace constants {
        static constexpr const auto ENEMY_QUERY = "SELECT naam, omschrijving, minimumobjecten, maximumobjecten, levenspunten, aanvalskans, minimumschade, maximumschade FROM Vijanden WHERE naam = ?";
        static constexpr const auto ITEM_QUERY = "SELECT naam, omschrijving, type, minimumwaarde, maximumwaarde FROM Objecten WHERE naam = ?";
    }

    BaseRepository::BaseRepository() {

    }

    BaseRepository::~BaseRepository() {
        sqlite3_close(db_);
    }

    int BaseRepository::open() {
        if (sqlite3_open(DEFAULT_DB_PATH, &db_) != SQLITE_OK) {
            sqlite3_close(db_);
            return -1;
        }
        return 0;
    }

//    int BaseRepository::close() {
//        return sqlite3_close(db_);
//    }

    game_objects::EnemyObject* BaseRepository::get_enemy(const char* name) {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::ENEMY_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
            return nullptr;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            const auto description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const auto min_obj = sqlite3_column_int(stmt, 2);
            const auto max_obj = sqlite3_column_int(stmt, 3);
            const auto health = sqlite3_column_int(stmt, 4);
            const auto attack_chance = sqlite3_column_int(stmt, 5);
            const auto min_damage = sqlite3_column_int(stmt, 6);
            const auto max_damage = sqlite3_column_int(stmt, 7);

            return new game_objects::EnemyObject(health, name, description);
        }
        return nullptr;
    }

    game_objects::GameObject* BaseRepository::get_item(const char* name) {
        return nullptr;
    }
}
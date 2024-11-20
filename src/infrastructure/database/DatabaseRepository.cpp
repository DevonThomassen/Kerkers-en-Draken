#include "../../domain/database/DatabaseRepository.hpp"

#include <sqlite3.h>
#include <iostream>
#include <cstring>

#include "../../domain/common/RandomEngine.hpp"
#include "../../domain/factories/EnemyFactory.h"
#include "../../domain/factories/GameObjectFactory.h"

namespace database {

    /**
     * @var db_
     * @brief A static variable that represents the database.
     */
    static sqlite3* db_ = nullptr;

    /**
     * @namespace constants
     * @brief Contains constants for the DatabaseRepository class.
     */
    namespace constants {
        static constexpr const auto ENEMY_QUERY = "SELECT naam, omschrijving, minimumobjecten, maximumobjecten, levenspunten, aanvalskans, minimumschade, maximumschade FROM Vijanden WHERE naam = ?";
        static constexpr const auto ITEM_QUERY = "SELECT naam, omschrijving, type, minimumwaarde, maximumwaarde, bescherming FROM Objecten WHERE naam = ?";
        static constexpr const auto ARMOUR = "wapenuitrusting";
    }

    int DatabaseRepository::open() {
        if (sqlite3_open(DEFAULT_DB_PATH, &db_) != SQLITE_OK) {
            sqlite3_close(db_);
            return -1;
        }
        return 0;
    }

    game_objects::EnemyObject* DatabaseRepository::get_enemy(const char* name) {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::ENEMY_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }

        auto& randomEngine = RandomEngine::get_instance();
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto name_string = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            const auto description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
//            const auto min_obj = sqlite3_column_int(stmt, 2);
//            const auto max_obj = sqlite3_column_int(stmt, 3);
            const auto health = sqlite3_column_int(stmt, 4);
            const auto attack_chance = sqlite3_column_int(stmt, 5);
            const auto min_damage = sqlite3_column_int(stmt, 6);
            const auto max_damage = sqlite3_column_int(stmt, 7);

            const auto random_damage = randomEngine.generate_random_number(min_damage, max_damage);

            return factories::EnemyFactory::create(health, attack_chance, random_damage, name_string, description);
        }
        return nullptr;
    }

    game_objects::GameObject* DatabaseRepository::get_item(const char* name, bool invisible) {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::ITEM_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }

        auto& randomEngine = RandomEngine::get_instance();
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto name_string = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            const auto description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const auto type_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));

            if (strcmp(type_name, constants::ARMOUR) == 0) {
                const auto protection = sqlite3_column_int(stmt, 5);
                return factories::GameObjectFactory::create(type_name, name_string, description, protection, invisible);
            }

            const auto min_value = sqlite3_column_int(stmt, 3);
            const auto max_value = sqlite3_column_int(stmt, 4);
            const auto r_value = randomEngine.generate_random_number(min_value, max_value);

            return factories::GameObjectFactory::create(type_name, name_string, description, r_value, invisible);
        }
        return nullptr;
    }

    int DatabaseRepository::close() {
        return sqlite3_close(db_);
    }
} // database;
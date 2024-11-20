#include "../../domain/database/DatabaseRepository.hpp"

#include <sqlite3.h>
#include <iostream>
#include <cstring>

#include "../../domain/common/Leaderboard.h"

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
     * @namespace database::constants
     * @brief Contains constants for the DatabaseRepository class.
     */
    namespace constants {
        /**
         * @namespace database::constants::queries
         * @brief Contains queries for the DatabaseRepository class.
         */
        namespace queries {
            static constexpr const auto ENEMY_QUERY = "SELECT naam, omschrijving, minimumobjecten, maximumobjecten, levenspunten, aanvalskans, minimumschade, maximumschade FROM Vijanden WHERE naam = ?";
            static constexpr const auto ITEM_QUERY = "SELECT naam, omschrijving, type, minimumwaarde, maximumwaarde, bescherming FROM Objecten WHERE naam = ?";
            static constexpr const auto LEADERBOARD_QUERY = "SELECT ID, naam, goudstukken FROM Leaderboard";
            static constexpr const auto GET_LEADERBOARD_ROW_QUERY = "SELECT ID, naam, goudstukken FROM Leaderboard WHERE naam = ?";
        }
        static constexpr const auto ARMOUR = "wapenuitrusting";
    }

    int DatabaseRepository::open() {
        if (sqlite3_open(DEFAULT_DB_PATH, &db_) != SQLITE_OK) {
            sqlite3_close(db_);
            return -1;
        }
        return 0;
    }

    int DatabaseRepository::close() {
        return sqlite3_close(db_);
    }

    game_objects::EnemyObject* DatabaseRepository::get_enemy(const char* name) {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::queries::ENEMY_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
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
        if (sqlite3_prepare_v2(db_, constants::queries::ITEM_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
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

    domain::Leaderboard* DatabaseRepository::get_leaderboard() {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::queries::LEADERBOARD_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        int row_count = 0;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            ++row_count;
        }
        sqlite3_reset(stmt);
        auto* leaderboard = new domain::Leaderboard(row_count);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const auto gold = sqlite3_column_int(stmt, 2);
            leaderboard->rows.push_back(new domain::LeaderboardRow(name, gold));
        }
        return leaderboard;
    }

    domain::LeaderboardRow* DatabaseRepository::get_leaderboard_row(const char* name) {
        sqlite3_stmt* stmt = nullptr;
        if (sqlite3_prepare_v2(db_, constants::queries::LEADERBOARD_QUERY, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK) {
            std::cerr << sqlite3_errmsg(db_) << std::endl;
            return nullptr;
        }
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const auto player_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            const auto gold = sqlite3_column_int(stmt, 2);
            return new domain::LeaderboardRow(player_name, gold);
        }
        return nullptr;
    }

    void DatabaseRepository::create_leaderboard_row() {

    }
} // database;
#include "../../domain/database/LeaderboardRepository.hpp"
#include <sqlite3.h>
#include <cstring>

using namespace domain;

namespace database {

    /**
     * @var db_
     * @brief A static variable that represents the database.
     */
    static sqlite3* db_ = nullptr;

//    const char* READ_LEADERBOARD_QUERY = "SELECT naam, goudstukken FROM leaderboard";

    LeaderboardRepository::LeaderboardRepository() {

    }

    int LeaderboardRepository::create_row(const char* name, const int gold_amount) const {
//        sqlite3_stmt* stmt = nullptr;
//        sqlite3_prepare_v2(db_, "INSERT INTO leaderboard (naam, goudstukken) VALUES (?, ?)", -1, &stmt, nullptr);
//        sqlite3_bind_text(stmt, 1, name, strlen(name), SQLITE_STATIC);
//        sqlite3_bind_int(stmt, 2, gold_amount);
//        sqlite3_step(stmt);
//        return sqlite3_finalize(stmt);
        return 0;
    }

    Leaderboard* LeaderboardRepository::read_leaderboard() {
//        sqlite3_stmt* stmt = nullptr;
//        auto* leaderboard = new Leaderboard();
//        leaderboard->rows = nullptr;
//        int row_count = 0;
//
//        if (sqlite3_prepare_v2(db_, "SELECT naam, goudstukken FROM leaderboard", -1, &stmt, nullptr) == SQLITE_OK) {
//            while (sqlite3_step(stmt) == SQLITE_ROW) {
//                const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
//                const int gold = sqlite3_column_int(stmt, 1);
//
//                auto* new_rows = new LeaderboardRow[row_count + 1];
//
//                for (int i = 0; i < row_count; ++i) {
//                    new_rows[i] = leaderboard->rows[i];
//                }
//
//                new_rows[row_count].name = strdup(name);
//                new_rows[row_count].gold = gold;
//
//                delete[] leaderboard->rows;
//
//                leaderboard->rows = new_rows;
//                ++row_count;
//            }
//            sqlite3_finalize(stmt);
//        } else {
//            delete leaderboard;
//            return nullptr;
//        }
//        leaderboard->row_count = row_count;
//        return leaderboard;
        return nullptr;
    }

}

#include "Leaderboard.h"

namespace domain {

    LeaderboardRow::LeaderboardRow() : name(nullptr), gold(0) {}

    LeaderboardRow::~LeaderboardRow() {
        delete[] name;
    }

    Leaderboard::Leaderboard(LeaderboardRow* rows, int row_count)
            : rows(rows), row_count(row_count) {}

    Leaderboard::Leaderboard()
            : rows(nullptr), row_count(0) {}

    Leaderboard::~Leaderboard() {
        delete[] rows;
    }
}
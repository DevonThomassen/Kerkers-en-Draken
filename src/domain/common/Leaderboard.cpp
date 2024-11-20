#include "Leaderboard.h"

namespace domain {

    LeaderboardRow::LeaderboardRow(const char* name, const int gold)
            : name(name), gold(gold) {}

    LeaderboardRow::~LeaderboardRow() {
        delete[] name;
    }

    Leaderboard::Leaderboard(int size) {
        rows = Array<LeaderboardRow>(size);
    }
}
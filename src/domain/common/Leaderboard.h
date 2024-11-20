#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "Array.hpp"

namespace domain {
    /**
     * @struct LeaderboardRow
     * @brief Represents a row in the leaderboard.
     */
    struct LeaderboardRow {
        const char* name;
        const int gold;

        explicit LeaderboardRow(const char* name, int gold);
        ~LeaderboardRow();
    };

    /**
     * @struct Leaderboard
     * @brief Represents a leaderboard.
     */
    struct Leaderboard {
        /**
         * @var rows
         * @brief An array of leaderboard rows.
         */
        Array<LeaderboardRow> rows;

        explicit Leaderboard(int size);
    };
}

#endif //LEADERBOARD_H

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

namespace domain {
    /**
     * @struct LeaderboardRow
     * @brief Represents a row in the leaderboard.
     */
    struct LeaderboardRow {
        char* name;
        int gold;

        LeaderboardRow();
        ~LeaderboardRow();
    };

    /**
     * @struct Leaderboard
     * @brief Represents a leaderboard.
     */
    struct Leaderboard {
        LeaderboardRow* rows;
        int row_count;

        explicit Leaderboard(LeaderboardRow* rows, int row_count);
        Leaderboard();
        ~Leaderboard();
    };
}

#endif //LEADERBOARD_H

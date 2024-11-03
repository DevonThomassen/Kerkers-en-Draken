#ifndef LEADERBOARDREPOSITORY_HPP
#define LEADERBOARDREPOSITORY_HPP

#include "../common/Leaderboard.h"
#include "DatabaseRepository.hpp"

using namespace domain;

namespace database {

    /**
     * @class LeaderboardRepository
     * @brief A class that represents a database for leaderboards.
     */
    class LeaderboardRepository final {
    public:
        explicit LeaderboardRepository();
        int create_row(const char* name, const int gold_amount) const;
        Leaderboard* read_leaderboard();

    private:
    };

}

#endif //LEADERBOARDREPOSITORY_HPP

#ifndef GAME_HPP
#define GAME_HPP

#include "Location.hpp"

namespace domain {
    /**
     * @class Game
     * @brief Represents the game.
     */
    class Game final {
    public:
        explicit Game();
        ~Game();
    private:
        Location* locations_;
        int max_locations_;
    };
}

#endif //GAME_HPP

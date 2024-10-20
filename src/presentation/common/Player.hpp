#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include "common/Array.hpp"
#include "common/IPlayer.hpp"
#include "gameobject/incl/ArmourObject.hpp"
#include "gameobject/incl/GoldObject.hpp"
#include "gameobject/incl/WeaponObject.hpp"

using namespace domain;
using namespace game_objects;

namespace presentation {

    /**
     * @class Player
     * @brief Represents a player in the game.
     */
    class Player final {
    public:
        /**
         * @brief Construct a new Player object
         * @param name The name of the player
         */
        explicit Player(std::string  name);
        ~Player();

        void take_damage(int amount);
        [[nodiscard]] int get_health() const;

    private:
        const std::string name_;
        static const int health_ = 20;
        static const int attack_chance_ = 40;
        Array<WeaponObject> weapons_;
        Array<ArmourObject> armour_objects_;
        Array<GoldObject> gold_amount_;
    };
}

#endif //PLAYER_HPP

#include "Player.hpp"

#include <utility>

namespace presentation {

    Player::Player(std::string name)
            : name_(std::move(name)),
              weapons_(),
              armour_objects_(),
              gold_amount_() {
    }

    Player::~Player() {
    }

    void Player::take_damage(int amount) {

    }

    int Player::get_health() const {
        return 0;
    }
}

#include "Player.hpp"

#include <utility>

namespace presentation {

    Player::Player(std::string name)
            : name_(std::move(name)),
              health_(START_HEALTH),
              objects_(nullptr) {}
//              weapons_(),
//              armour_objects_(),
//              gold_amount_()

    Player::~Player() {
    }

    void Player::take_damage(const int amount) {

    }

    std::string Player::get_name() const {
        return name_;
    }

    int Player::get_health() const {
        return health_;
    }

    int Player::get_attack_chance() const {
        return attack_chance_;
    }
}

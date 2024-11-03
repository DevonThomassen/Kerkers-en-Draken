#include "Player.hpp"

#include <memory>
#include <utility>

#include "gameobject/incl/GameObject.hpp"

namespace presentation {

    Player::Player(std::string name)
            : name_(std::move(name)),
              health_(START_HEALTH),
              objects_() {}

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

    void Player::add_object(std::unique_ptr<GameObject> object) {
        objects_.push_back(std::move(object));
    }
}

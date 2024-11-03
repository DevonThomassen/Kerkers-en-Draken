#include "Player.hpp"

#include <memory>
#include <utility>

#include "gameobject/incl/ArmourObject.hpp"
#include "gameobject/incl/ConsumableObject.hpp"
#include "gameobject/incl/GoldObject.hpp"
#include "gameobject/incl/WeaponObject.hpp"

namespace presentation {

    namespace constants {
        static constexpr const std::string NOTHING = "Geen";
    }

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

    const std::vector<std::unique_ptr<GameObject>>& Player::get_objects() const {
        return objects_;
    }

    std::string Player::get_weapon_name() const {
        for (const auto& weapon: objects_) {
            if (const auto* weapon_object = dynamic_cast<WeaponObject*>(weapon.get())) {
                return {weapon->get_name()};
            }
        }
        return constants::NOTHING;
    }

    std::string Player::get_armour_name() const {
        std::string default_string = "Geen armour";
        for (const auto& armour: objects_) {
            if (const auto* weapon_object = dynamic_cast<ArmourObject*>(armour.get())) {
                return {armour->get_name()};
            }
        }
        return constants::NOTHING;
    }

    int Player::get_gold() const {
        for (const auto& gold: objects_) {
            if (const auto* gold_object = dynamic_cast<GoldObject*>(gold.get())) {
                return gold_object->get_amount();
            }
        }
        return 0;
    }

    std::string Player::get_consumable_names() const {
        std::string string = "";
        for (const auto& consumable: objects_) {
            if (const auto* weapon_object = dynamic_cast<ConsumableObject*>(consumable.get())) {
                string += std::string(consumable->get_name()) + "\n";
            }
        }
        if (string == "") {
            return constants::NOTHING;
        }
        return string;
    }

    void Player::add_object(GameObject* game_object) {
        objects_.push_back(std::unique_ptr<GameObject>(game_object));
    }

    GameObject* Player::remove_object(const std::string& name) {
        for (auto& object : objects_) {
            if (object->get_name() == name) {
                auto temp = object.release();
                objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
                return temp;
            }
        }
        return nullptr;
    }
} // presentation

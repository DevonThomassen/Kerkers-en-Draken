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
              attack_chance_(40),
              god_mode_(false),
              weapon_(),
              armour_(),
              objects_() {}

    Player::~Player() = default;

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
        return weapon_ != nullptr
               ? weapon_->get_name()
               : constants::NOTHING;
    }

    std::string Player::get_armour_name() const {
        return armour_ != nullptr
               ? armour_->get_name()
               : constants::NOTHING;
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
        std::string string;
        for (const auto& consumable: objects_) {
            if (const auto* weapon_object = dynamic_cast<ConsumableObject*>(consumable.get())) {
                string += std::string(consumable->get_name()) + "\n";
            }
        }
        if (string.empty()) {
            return constants::NOTHING;
        }
        return string;
    }

    std::string Player::get_all_objects_names() const {
        std::string string;
        for (const auto& object: objects_) {
            if (dynamic_cast<ArmourObject*>(object.get())
                || dynamic_cast<WeaponObject*>(object.get())
                || dynamic_cast<ConsumableObject*>(object.get())) {
                string += std::string(object->get_name()) + "\n";
            }
        }
        if (string.empty()) {
            return constants::NOTHING;
        }
        return string;
    }

    void Player::add_object(GameObject* game_object) {
        objects_.push_back(std::unique_ptr<GameObject>(game_object));
    }

    GameObject* Player::remove_object(const std::string& name) {
        for (auto& object: objects_) {
            if (object->get_name() == name) {
                auto temp = object.release();
                objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
                return temp;
            }
        }
        return nullptr;
    }

    int Player::consume(ConsumableObject* consumable) {
        const auto value = consumable->get_value();
        const auto type = std::string(consumable->get_type());
        if (type == "levenselixer") {
            health_ += value;
            return 0;
        }
        if (type == "ervaringsdrank") {
            attack_chance_ += value;
            return 0;
        }
        if (type == "teleportatiedrank") {
            return 1;
        }
        return -1;
    }

    bool Player::equip_in_hand(const std::string& name) {
        if (weapon_ != nullptr) {
            objects_.push_back(std::move(weapon_));
        }
        for (auto it = objects_.begin(); it != objects_.end(); ++it) {
            if ((*it)->get_name() == name) {
                if (dynamic_cast<ArmourObject*>((*it).get())) {
                    armour_ = std::move(*it);
                    objects_.erase(it);
                    return true;
                }
                if (dynamic_cast<WeaponObject*>((*it).get())) {
                    weapon_ = std::move(*it);
                    objects_.erase(it);
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void Player::toggle_god_mode() {
        god_mode_ = !god_mode_;
    }

    bool Player::is_god_mode() const {
        return god_mode_;
    }

} // presentation

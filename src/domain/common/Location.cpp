#include "Location.hpp"

#include <cstring>

#include "../gameobject/incl/GameObject.hpp"
#include "../gameobject/incl/EnemyObject.hpp"
#include "../../domain/common/Direction.hpp"
#include "RandomEngine.hpp"

namespace domain {

    Location::Location(const int id, const char* name, const char* description)
            : id_(id),
              name_(name),
              description_(description),
              objects_(3),
              exits_() {}
//              exits_(3) {}

    Location::Location(const domain::Location& other) {
        id_ = other.id_;
        name_ = other.name_;
        description_ = other.description_;
        objects_ = other.objects_;
        exits_ = other.exits_;
    }

    Location::Location(Location&& other) noexcept {
        id_ = other.id_;
        name_ = other.name_;
        description_ = other.description_;
        objects_ = other.objects_;
        exits_ = other.exits_;
    }

    Location& Location::operator=(const Location& other) {
        if (this == &other) {
            return *this;
        }
        id_ = other.id_;
        name_ = other.name_;
        description_ = other.description_;
        objects_ = other.objects_;
        exits_ = other.exits_;
        return *this;
    }

    Location& Location::operator=(Location&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        id_ = other.id_;
        name_ = other.name_;
        description_ = other.description_;
        objects_ = other.objects_;
        exits_ = other.exits_;
        return *this;
    }

    Location::~Location() {
        delete[] name_;
    }

    int Location::id() const {
        return id_;
    }

    const char* Location::name() const {
        return name_;
    }

    const char* Location::simple_description() const {
        return description_;
    }

    const char* Location::complete_description() const {
        return "TODO: This should be a complete description of the location.";
    }

    int Location::add_exit(Direction direction, Location* destination) {
        if (destination == nullptr) {
            return -1;
        }
        exits_.add_exit(direction, destination);
        return 0;
    }

    int Location::add_object(game_objects::GameObject* game_object) {
        if (game_object == nullptr) {
            return -1;
        }
        objects_.push_back(game_object);
        return 0;
    }

    int Location::get_exit(Direction direction) const {
        const auto* exit = exits_.get_exit(direction);
        return exit
               ? exit->destination->id()
               : -1;
    }

    const char* Location::get_possible_directions() const {
        return exits_.get_possible_directions();
    }

    game_objects::GameObject* Location::take_object(const char* name) {
        for (auto i = 0; i < objects_.size(); ++i) {
            auto object = objects_[i];
            if (object->is_invisible()) {
                continue;
            }
            if (strcmp(object->get_name(), name) == 0) {
                auto* game_object = objects_[i];
                objects_.remove_at_index(i);
                return game_object;
            }
        }
        return nullptr;
    }

    const Array<game_objects::GameObject>& Location::get_objects() const {
        return objects_;
    }

    void Location::search_room() {
        for (auto i = 0; i < objects_.size(); ++i) {
            if (dynamic_cast<game_objects::EnemyObject*>(objects_[i]) != nullptr) {
                return;
            }
        }
        for (auto i = 0; i < objects_.size(); ++i) {
            if (objects_[i]->is_invisible()) {
                objects_[i]->set_invisible(false);
            }
        }
    }

    void Location::move_enemies() {
        for (auto i = 0; i < objects_.size(); ++i) {
            auto* enemy = dynamic_cast<game_objects::EnemyObject*>(objects_[i]);
            if (enemy != nullptr && enemy->get_health() > 0) {
                auto result = RandomEngine::get_instance().hit_percentage(50);
                if (result.has_value() && result.value()) {
                    exits_.get_random_exit()->destination->add_object(enemy);
                    objects_.remove_at_index(i);
                }
            }
        }
    }

    Exit* Location::get_random_exit() {
        return exits_.get_random_exit();
    }

    int Location::total_damage_room() {
        auto total_damage = 0;
        for (auto i = 0; i < objects_.size(); ++i) {
            auto* enemy = dynamic_cast<game_objects::EnemyObject*>(objects_[i]);
            if (enemy != nullptr) {
                total_damage += enemy->get_damage();
            }
        }
        return total_damage;
    }
} // domain

#include "../incl/GameObject.hpp"

namespace game_objects {

    GameObject::GameObject(const char* name, const char* description, const bool invisible)
            : name_(name), description_(description), invisible_(invisible) {}

    GameObject::GameObject(const GameObject& other) = default;
    GameObject::GameObject(GameObject&& other) noexcept = default;
    GameObject& GameObject::operator=(const GameObject& other) = default;
    GameObject& GameObject::operator=(GameObject&& other) noexcept = default;

    const char* GameObject::get_name() const {
        return name_;
    }

    const char* GameObject::get_description() const {
        return description_;
    }

    bool GameObject::is_invisible() const {
        return invisible_;
    }

} // game_objects


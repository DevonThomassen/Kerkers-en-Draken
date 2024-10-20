#include "../incl/GameObject.hpp"

namespace game_objects {

    GameObject::GameObject(const char* name, const char* description)
            : name_(name), description_(description) {}

    GameObject::GameObject(const GameObject& other) = default;
    GameObject::GameObject(GameObject&& other) noexcept = default;
    GameObject& GameObject::operator=(const GameObject& other) = default;
    GameObject& GameObject::operator=(GameObject&& other) noexcept = default;

}


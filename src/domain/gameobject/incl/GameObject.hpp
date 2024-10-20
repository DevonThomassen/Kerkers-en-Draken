#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

namespace game_objects {
    /**
     * @class GameObject
     * @brief A class that represents a base game object in the game.
     */
    class GameObject {
    public:
        explicit GameObject(const char* name, const char* description);
        GameObject(const GameObject& other);
        GameObject(GameObject&& other) noexcept;
        GameObject& operator=(const GameObject& other);
        GameObject& operator=(GameObject&& other) noexcept;
        virtual ~GameObject() = default;

    private:
        const char* name_;
        const char* description_;
    };
}

#endif //GAMEOBJECT_HPP

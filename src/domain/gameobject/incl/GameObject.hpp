#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

/**
 * @namespace game_objects
 * @brief Contains game objects.
 */
namespace game_objects {
    /**
     * @class GameObject
     * @brief A class that represents a base game object in the game.
     */
    class GameObject {
    public:
        explicit GameObject(const char* name, const char* description, bool invisible = false);
        GameObject(const GameObject& other);
        GameObject(GameObject&& other) noexcept;
        GameObject& operator=(const GameObject& other);
        GameObject& operator=(GameObject&& other) noexcept;
        virtual ~GameObject() = default;

        /**
         * @brief Get the name of the game object.
         * @return The name of the game object.
         */
        [[nodiscard]] const char* get_name() const;

        /**
         * @brief Get the description of the game object.
         * @return The description of the game object.
         */
        [[nodiscard]] const char* get_description() const;

        /**
         * @brief Get the invisibility of the game object.
         * @return The invisibility of the game object.
         */
        [[nodiscard]] bool is_invisible() const;

        /**
         * @brief Set the invisibility of the game object.
         * @param invisible The invisibility of the game object.
         */
        void set_invisible(bool invisible);

    private:
        const char* name_;
        const char* description_;
        bool invisible_;
    };
}

#endif //GAMEOBJECT_HPP

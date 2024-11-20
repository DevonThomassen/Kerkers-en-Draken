#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

namespace game_objects {
    class GameObject;
    class ConsumableObject;
}

using namespace game_objects;

namespace presentation {

    /**
     * @brief The starting health of a player.
     */
    static constexpr const int START_HEALTH = 20;

    /**
     * @class Player
     * @brief Represents a player in the game.
     */
    class Player final {
    public:
        /**
         * @brief Construct a new Player object
         * @param name The name of the player
         */
        explicit Player(std::string name);
        ~Player();

        void take_damage(int amount);

        [[nodiscard]] std::string get_name() const;
        [[nodiscard]] int get_attack_chance() const;
        [[nodiscard]] int get_health() const;
        void add_object(std::unique_ptr<GameObject> object);
        [[nodiscard]] const std::vector<std::unique_ptr<GameObject>>& get_objects() const;

        [[nodiscard]] std::string get_weapon_name() const;
        [[nodiscard]] std::string get_armour_name() const;
        [[nodiscard]] int get_gold() const;
        [[nodiscard]] std::string get_consumable_names() const;
        [[nodiscard]] std::string get_all_objects_names() const;

        void add_object(GameObject* game_object);
        GameObject* remove_object(const std::string& name);

        bool equip_in_hand(const std::string& name);
        int consume(ConsumableObject* consumable);

        void toggle_god_mode();
        [[nodiscard]] bool is_god_mode() const;
        [[nodiscard]] int do_attack() const;

    private:
        const std::string name_;
        int health_;
        int attack_chance_;
        bool god_mode_;
        std::unique_ptr<GameObject> weapon_;
        std::unique_ptr<GameObject> armour_;
        std::vector<std::unique_ptr<GameObject>> objects_;
    };
}

#endif //PLAYER_HPP

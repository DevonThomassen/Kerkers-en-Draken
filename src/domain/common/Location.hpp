#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Array.hpp"
#include "Exit.h"

namespace game_objects {
    class GameObject;
    class EnemyObject;
}

namespace domain {

    class Location final {
    public:
        explicit Location(int id, const char* name, const char* description);
        Location(const Location& other);
        Location(Location&& other) noexcept;
        Location& operator=(const Location& other);
        Location& operator=(Location&& other) noexcept;
        ~Location();

        /**
         * @brief Returns the id of the location.
         * @return The id of the location.
         */
        [[nodiscard]] int id() const;

        /**
         * @brief Returns the name of the location.
         * @return The name of the location.
         */
        [[nodiscard]] const char* name() const;

        /**
         * @brief Returns the simple description of the location.
         * @return The simple description of the location.
         */
        [[maybe_unused]] [[nodiscard]] const char* simple_description() const;

        /**
         * @brief Returns the complete description of the location.
         * @return The complete description of the location.
         */
        [[maybe_unused]] [[nodiscard]] const char* complete_description() const;

        /**
         * @brief Adds an exit to the location.
         * @param direction The direction of the exit.
         * @param destination The destination of the exit.
         * @return 0 if the exit was added successfully, -1 otherwise.
         */
        [[maybe_unused]] int add_exit(Direction direction, Location* destination);

        Exit& get_exit(Direction direction);

        int add_object(game_objects::GameObject* game_object);

    private:
        int id_;
        const char* name_;
        const char* description_;
        Array<game_objects::GameObject> objects_;
        ExitManager exits_;
    };
}

#endif //LOCATION_HPP

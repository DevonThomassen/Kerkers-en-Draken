#ifndef DUNGEONBUILDER_HPP
#define DUNGEONBUILDER_HPP

#include "../common/Array.hpp"

namespace game_objects {
    class EnemyObject;
    class GameObject;
}

namespace domain {
    class Location;
    enum class Direction;
}

/**
 * @namespace domain::builder
 * @brief Builder pattern for initializing a dungeon
 */
namespace domain::builder {
    /**
     * @class DungeonBuilder
     * @brief A class that represents a builder for a dungeon
     */
    class DungeonBuilder final {
    public:
        explicit DungeonBuilder(int capacity);
        ~DungeonBuilder();

        /**
         * @brief Adds a location to the dungeon
         * @param id The id of the location
         * @param name The name of the location
         * @param description The description of the location
         */
        void add_location(int id, const char* name, const char* description);

        /**
         * @brief Binds two locations together
         * @param src The source location
         * @param dest The destination location
         * @param direction The direction from the source to the destination
         * @return 0 if successful, -1 if the source location is not found, -2 if the destination location is not found
         */
        int bind_locations(int src, int dest, Direction direction);

        void bind_enemy_to_location(int location_id, game_objects::EnemyObject* enemy);

        void bind_game_object_to_location(int location_id, game_objects::GameObject* game_object);

        /**
         * @brief Gets the locations of the dungeon
         * @return The locations of the dungeon
         */
        [[nodiscard]] Array<Location>* get_locations();

    private:
        Array<Location>* locations_;

        /**
         * @brief Finds a location by its id
         * @param id The id of the location
         * @return The location if found, nullptr otherwise
         */
        [[nodiscard]] Location* find_location_by_id(int id) const;
    };
} // builder

#endif //DUNGEONBUILDER_HPP

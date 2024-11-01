#ifndef DUNGEONBUILDER_HPP
#define DUNGEONBUILDER_HPP

#include "../factories/LocationFactory.h"

namespace domain {
    enum class Direction;
}

using namespace domain;
using namespace factories;

namespace builder {

    class DungeonBuilder final {
    public:
        explicit DungeonBuilder(int capacity);
        ~DungeonBuilder();

        /**
         * @brief Adds a location to the dungeon
         * @param id The id of the location
         * @param name The name of the location
         */
        void add_location(int id, const char* name);

        /**
         * @brief Binds two locations together
         * @param src The source location
         * @param dest The destination location
         * @param direction The direction from the source to the destination
         */
        void bind_locations(int src, int dest, Direction direction);

        /**
         * @brief Gets the locations of the dungeon
         * @return The locations of the dungeon
         */
        [[nodiscard]] Array<Location> get_locations() const;

    private:
        Array<Location> locations_;
    };
} // builder

#endif //DUNGEONBUILDER_HPP

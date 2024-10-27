#ifndef DIRECTION_HPP
#define DIRECTION_HPP

namespace domain {
    /*
     * Constants for the directions
     */
    namespace constants {
        static const char* NORTH_STR = "North";
        static const char* SOUTH_STR = "South";
        static const char* EAST_STR = "East";
        static const char* WEST_STR = "West";
    } // constants

    enum class Direction {
        North,
        South,
        East,
        West
    };

    [[nodiscard]] Direction opposite(Direction direction) {
        switch (direction) {
            case Direction::North:
                return Direction::South;
            case Direction::South:
                return Direction::North;
            case Direction::East:
                return Direction::West;
            case Direction::West:
                return Direction::East;
        }
    }

    [[nodiscard]] const char* to_string(Direction direction) {
        switch (direction) {
            case Direction::North:
                return constants::NORTH_STR;
            case Direction::South:
                return constants::SOUTH_STR;
            case Direction::East:
                return constants::EAST_STR;
            case Direction::West:
                return constants::WEST_STR;
        }
    }
} // domain

#endif //DIRECTION_HPP

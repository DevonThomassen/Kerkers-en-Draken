#ifndef DIRECTION_HPP
#define DIRECTION_HPP

namespace common {
    enum class Direction {
        North,
        South,
        East,
        West
    };

    const char* to_string(Direction direction) {
        switch (direction) {
            case Direction::North:
                return "North";
            case Direction::South:
                return "South";
            case Direction::East:
                return "East";
            case Direction::West:
                return "West";
        }
    }
}

#endif //DIRECTION_HPP

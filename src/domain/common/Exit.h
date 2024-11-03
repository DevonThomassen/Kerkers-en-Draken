#ifndef EXIT_H
#define EXIT_H

namespace domain {

    enum class Direction;
    class Location;

    /**
     * @struct Exit
     * @brief A struct that represents an exit in a location.
     */
    struct Exit {
        Direction direction;
        Location* destination;
    };

} // domain

#endif //EXIT_H

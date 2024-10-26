#ifndef LOCATIONFACTORY_H
#define LOCATIONFACTORY_H

#include "../common/Location.hpp"

namespace factories {

    /**
     * @namespace consts
     * @brief A namespace for constants used in the LocationFactory class.
     */
    namespace consts {
        const static int MIN_VISIBLE_OBJECTS = 0;
        const static int MAX_VISIBLE_OBJECTS = 3;

        const static int MIN_INVISIBLE_OBJECTS = 0;
        const static int MAX_INVISIBLE_OBJECTS = 2;

        const static int MIN_EXISTS = 1;
        const static int MAX_EXISTS = 4;

        const static int ENEMY_PER_ROOM = 3;
    } // consts
    /**
     * @struct LocationFactory
     * @brief A factory class for creating Location objects.
     */
    struct LocationFactory {
        /**
         * @brief Creates a Location object with the given x and y coordinates.
         * @param name The name of the location.
         * @param x The x coordinate of the location.
         * @param y The y coordinate of the location.
         * @return A Location pointer with the given x and y coordinates.
         */
        static domain::Location* create(const char* name, const int x, const int y) {
            return new domain::Location(name, x, y);
        }
    };
} // factories

#endif //LOCATIONFACTORY_H

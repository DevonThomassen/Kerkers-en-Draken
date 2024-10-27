#ifndef LOCATIONFACTORY_H
#define LOCATIONFACTORY_H

#include "../common/Location.hpp"

namespace factories {

    /**
     * @namespace consts
     * @brief A namespace for constants used in the LocationFactory class.
     */
    namespace consts {
        static const int MIN_VISIBLE_OBJECTS = 0;
        static const int MAX_VISIBLE_OBJECTS = 3;

        static const int MIN_INVISIBLE_OBJECTS = 0;
        static const int MAX_INVISIBLE_OBJECTS = 2;

        static const int MIN_EXISTS = 1;
        static const int MAX_EXISTS = 4;

        static const int ENEMY_PER_ROOM = 3;
    } // consts
    /**
     * @struct LocationFactory
     * @brief A factory class for creating Location objects.
     */
    struct LocationFactory {
        /**
         * @brief Creates a Location object with the given x and y coordinates.
         * @param name The name of the location.
         * @return A Location pointer with the given x and y coordinates.
         */
        static domain::Location* create(int id, const char* name) {
            return new domain::Location(id, name);
        }
    };
} // factories

#endif //LOCATIONFACTORY_H

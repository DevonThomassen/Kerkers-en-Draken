#ifndef LOCATIONFACTORY_H
#define LOCATIONFACTORY_H

#include "../common/Location.hpp"

namespace factories {

    /**
     * @class LocationFactory
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
}

#endif //LOCATIONFACTORY_H

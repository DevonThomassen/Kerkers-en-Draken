#ifndef LOCATIONFACTORY_H
#define LOCATIONFACTORY_H

namespace domain {
    class Location;
}

namespace factories {

    /**
     * @namespace factories::location::constants
     * @brief A namespace for constants used in the LocationFactory class.
     */
    namespace location::constants {
        static const int MIN_VISIBLE_OBJECTS = 0;
        static const int MAX_VISIBLE_OBJECTS = 3;

        static const int MIN_INVISIBLE_OBJECTS = 0;
        static const int MAX_INVISIBLE_OBJECTS = 2;

        static const int MIN_EXISTS = 1;
        static const int MAX_EXISTS = 4;

        static const int ENEMY_PER_ROOM = 3;
    } // constants
    /**
     * @struct LocationFactory
     * @brief A factory class for creating Location objects.
     */
    struct LocationFactory {
        /**
         * @brief Creates a Location object with the given id.
         * @param id The id of the location.
         * @param name The name of the location.
         * @param description The description of the location.
         * @return A Location pointer with the given id.
         */
        static domain::Location* create(int id, const char* name, const char* description);

        /**
         * @brief Creates a Location object with the given id.
         * @param id The id of the location.
         * @return A Location pointer with the given id.
         */
        static domain::Location* create(int id);
    };
} // factories

#endif //LOCATIONFACTORY_H

#ifndef LOCATIONREPOSITORY_HPP
#define LOCATIONREPOSITORY_HPP

#include "../common/Location.hpp"

using namespace domain;
namespace repository {

    /**
     * @class LocationRepository
     * @brief Repository for location data
     */
    class LocationRepository final {
    public:
        explicit LocationRepository();

        void create_location(const int x, const int y);
        Location* read_location();
        void update_location();
        void delete_location();

    };

}

#endif //LOCATIONREPOSITORY_HPP

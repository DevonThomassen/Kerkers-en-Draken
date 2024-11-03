#ifndef EXITMANAGER_HPP
#define EXITMANAGER_HPP

#include "Exit.h"

namespace domain {

    enum class Direction;
    class Location;

    /**
     * @class ExitManager
     * @brief Class for managing exits in a location.
     */
    class ExitManager {
    public:
        explicit ExitManager();
        ~ExitManager();

        bool add_exit(Direction direction, Location* destination);

        [[nodiscard]] Exit* get_exit(Direction direction) const;

        [[nodiscard]] const char* get_possible_directions() const ;

    private:
        Exit* exits_[4]{};
        int size_;
    };
}
#endif //EXITMANAGER_HPP

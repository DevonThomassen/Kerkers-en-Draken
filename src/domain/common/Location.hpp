#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Array.hpp"
#include "Direction.hpp"
#include "Exit.h"
#include "../gameobject/incl/EnemyObject.hpp"

namespace domain {

    class Location final {
    public:
        explicit Location(int id, const char* name);
        Location(const Location& other);
        Location(Location&& other) noexcept;
        Location& operator=(const Location& other);
        Location& operator=(Location&& other) noexcept;
        ~Location();

        [[nodiscard]] const char& name() const;
        [[nodiscard]] const char& simple_description() const;
        [[nodiscard]] const char& complete_description() const;

        void add_exit(Direction direction, Location* destination);

    private:
        int id_;
        const char* name_;
        Array<Exit> exits_;
    };
}

#endif //LOCATION_HPP

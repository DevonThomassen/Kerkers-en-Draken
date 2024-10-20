#ifndef LOCATION_HPP
#define LOCATION_HPP

#include "Array.hpp"
#include "../gameobject/incl/EnemyObject.hpp"

namespace domain {

    class Location {
    public:
        explicit Location(const char* name, int x, int y);
        ~Location();

        [[nodiscard]] const char& name() const;
        [[nodiscard]] const char& simple_description() const;
        [[nodiscard]] const char& complete_description() const;

    private:
        const char* name_;
        int x_;
        int y_;
//        Array<game_objects::GameObject> visible_objects_ = Array<game_objects::GameObject>(0);
//        Array<game_objects::GameObject> invisible_objects_ = Array<game_objects::GameObject>(0);
        // exits 1 or more
//        Array<game_objects::EnemyObject> enemies_ = Array<game_objects::EnemyObject>(0);
    };
}

#endif //LOCATION_HPP

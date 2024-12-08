#ifndef DUNGEONFACTORY_H
#define DUNGEONFACTORY_H

namespace domain {
    template<typename T>
    class Array;
    class Location;
}

using namespace domain;

namespace factories {

    Array<Location>* generate_dungeon(const int amount);

}

#endif //DUNGEONFACTORY_H

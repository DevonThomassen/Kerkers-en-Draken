#include "DungeonBuilder.hpp"

#include "../common/Direction.hpp"
#include "../factories/LocationFactory.h"

using namespace domain;

namespace builder {

    DungeonBuilder::DungeonBuilder(const int capacity)
            : locations_(capacity) {}

    DungeonBuilder::~DungeonBuilder() = default;

    void DungeonBuilder::add_location(int id, const char* name) {
        locations_.push_back(factories::LocationFactory::create(id, name));
    }

    void DungeonBuilder::bind_locations(const int src, const int dest, const Direction direction) {
        const auto source = locations_[src];
        const auto destination = locations_[dest];
        source->add_exit(direction, destination);
        destination->add_exit(opposite(direction), source);
    }

    Array<Location> DungeonBuilder::get_locations() const {
        return Array<Location>();
    }

} // builder
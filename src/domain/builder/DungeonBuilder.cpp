#include "DungeonBuilder.hpp"

#include "../factories/LocationFactory.h"
#include "../common/Direction.hpp"

#define SOURCE_NOT_FOUND (-1)
#define DESTINATION_NOT_FOUND (-2)

using namespace domain;

namespace builder {

    DungeonBuilder::DungeonBuilder(const int capacity)
            : locations_(new Array<Location>(capacity)) {}

    DungeonBuilder::~DungeonBuilder() {
        delete locations_;
    }

    void DungeonBuilder::add_location(int id, const char* name, const char* description) {
        locations_->push_back(factories::LocationFactory::create(id, name, description));
    }

    int DungeonBuilder::bind_locations(const int src, const int dest, const Direction direction) {
        auto source = (*locations_)[src - 1];
        if (source == nullptr or source->id() != src) {
            source = find_location_by_id(src);
        }
        if (source == nullptr) {
            return SOURCE_NOT_FOUND;
        }
        auto destination = (*locations_)[dest - 1];
        if (destination == nullptr or destination->id() != dest) {
            destination = find_location_by_id(dest);
        }
        if (destination == nullptr) {
            return DESTINATION_NOT_FOUND;
        }
        source->add_exit(direction, destination);
        return 0;
    }

    Array<Location>* DungeonBuilder::get_locations() {
        auto* location = locations_;
        locations_ = nullptr;
        return location;
    }

    Location* DungeonBuilder::find_location_by_id(int id) const {
        for (auto i = 0; i < locations_->size(); ++i) {
            auto* location = (*locations_)[i];
            if (location->id() == id) {
                return location;
            }
        }
        return nullptr;
    }

} // builder
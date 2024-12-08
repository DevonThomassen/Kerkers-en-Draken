#include "../../domain/factories/LocationFactory.h"
#include "../../domain/common/Location.hpp"

namespace factories {
    domain::Location* LocationFactory::create(int id, const char* name, const char* description) {
        return new domain::Location(id, name, description);
    }

    domain::Location* LocationFactory::create(int id) {
        return new domain::Location(id, "name", "description");
    }
} // factories
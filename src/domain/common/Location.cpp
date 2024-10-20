#include "Location.hpp"

namespace domain {

    Location::Location(const char* name, int x, int y)
            : name_(name),
              x_(x),
              y_(y) {}

    Location::~Location() {
        delete[] name_;
    }

    const char& Location::name() const {
        return *name_;
    }

    const char& Location::simple_description() const {
        return *"TODO: This should be a simple description of the location.";
    }

    const char& Location::complete_description() const {
        return *"TODO: This should be a complete description of the location.";
    }
} // domain

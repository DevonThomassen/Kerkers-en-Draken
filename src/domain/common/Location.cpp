#include "Location.hpp"

namespace domain {

    Location::Location(const domain::Location& other) {
        id_ = other.id_;
        name_ = other.name_;
//        exits_ = other.exits_;
    }

    Location::Location(Location&& other) noexcept {
        id_ = other.id_;
        name_ = other.name_;
//        exits_ = other.exits_;
    }

    Location& Location::operator=(const Location& other) {
        if (this == &other) {
            return *this;
        }
        id_ = other.id_;
        name_ = other.name_;
//        exits_ = other.exits_;
        return *this;
    }

    Location& Location::operator=(Location&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        id_ = other.id_;
        name_ = other.name_;
//        exits_ = other.exits_;
        return *this;
    }

    Location::Location(const int id, const char* name, const char* description)
            : id_(id),
              name_(name),
              description_(description),
              exits_(3) {}

    Location::~Location() {
        delete[] name_;
    }

    int Location::id() const {
        return id_;
    }

    const char* Location::name() const {
        return name_;
    }

    const char* Location::simple_description() const {
        return "TODO: This should be a simple description of the location.";
    }

    const char* Location::complete_description() const {
        return "TODO: This should be a complete description of the location.";
    }

    int Location::add_exit(Direction direction, Location* destination) {
//        for (auto i = 0; i < exits_.size(); i++) {
//            if (exits_[i]->direction == direction) {
//                return -1;
//            }
//        }
//        exits_.push_back(new Exit{direction, destination});
        return 0;
    }
} // domain

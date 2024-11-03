#include "ExitManager.hpp"

#include <cstring>

#include "Location.hpp"
#include "Direction.hpp"
#include "RandomEngine.hpp"

namespace domain {
    ExitManager::ExitManager() : size_(0) {
        for (auto& exit: exits_) {
            exit = nullptr;
        }
    }

    ExitManager::~ExitManager() {
        for (int i = 0; i < size_; ++i) {
            delete exits_[i];
        }
    }

    bool ExitManager::add_exit(Direction direction, Location* destination) {
        if (size_ >= 4 || destination == nullptr) {
            return false;
        }
        exits_[size_++] = new Exit{direction, destination};
        return true;
    }

    [[nodiscard]] Exit* ExitManager::get_exit(Direction direction) const {
        for (int i = 0; i < size_; ++i) {
            if (exits_[i]->direction == direction) {
                return exits_[i];
            }
        }
        return nullptr;
    }

    [[nodiscard]] const char* ExitManager::get_possible_directions() const {
        static char directions[256];
        directions[0] = '\0';
        for (int i = 0; i < size_; ++i) {
            if (i > 0) {
                std::strcat(directions, ", ");
            }
            std::strcat(directions, domain::to_string(exits_[i]->direction));
        }
        return directions;
    }

    Exit* ExitManager::get_random_exit() const {
        return exits_[RandomEngine::get_instance().generate_random_number(0, size_ - 1)];
    }
}
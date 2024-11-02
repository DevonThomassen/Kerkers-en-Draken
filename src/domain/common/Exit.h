#ifndef EXIT_H
#define EXIT_H

namespace domain {

    enum class Direction;

    class Location;

    /**
     * @struct Exit
     * @brief A struct that represents an exit in a location.
     */
    struct Exit {
        Direction direction;
        Location* destination;
    };

    class ExitManager {
    public:
        explicit ExitManager() : size_(0) {
            for (auto& exit: exits_) {
                exit = nullptr;
            }
        }

        ~ExitManager() {
            for (int i = 0; i < size_; ++i) {
                delete exits_[i];
            }
        }

        bool add_exit(Direction direction, Location* destination) {
            if (size_ >= 4 || destination == nullptr) {
                return false;
            }
            exits_[size_++] = new Exit{direction, destination};
            return true;
        }

        [[nodiscard]] Exit* get_exit(int index) const {
            if (index < 0 || index >= size_) {
                return nullptr;
            }
            return exits_[index];
        }

    private:
        Exit* exits_[4]{};
        int size_;
    };

} // domain

#endif //EXIT_H

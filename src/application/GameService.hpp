#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#define GAME_START_SUCCESS 0
#define GAME_START_FAILURE 1

#include "../domain/common/Array.hpp"

namespace domain {
    enum class Direction;
    class Location;
} // domain

using namespace domain;

/**
 * @namespace application
 * @brief The namespace for the application
 */
namespace application {
    /**
    * @class GameService
    * @brief Class for game commands
    */
    class GameService final {
    public:
        explicit GameService();
        ~GameService();

        /**
         * @brief Main loop for the game
         * @tparam Loop
         * @param loop
         */
        template<typename Loop>
        void main_loop(Loop loop) {
            while (!quit_) {
                loop();
                turn();
            }
        }

        /**
         * @brief Starts the game
         * @param location_amount
         */
        int start(int location_amount);

        /**
         * @brief Starts the game
         * @param file_path
         */
        int start(const char* file_path);

        void turn();

        /**
         * @brief Exits the game
         */
        void exit();

        [[nodiscard]] bool is_running() const;

        [[nodiscard]] Location& get_current_location() const;
        [[nodiscard]] Location* get_current_location_ptr() const;

        bool go_to_next_location(Direction direction);
        void teleport(int amount);
        [[nodiscard]] int damage_of_the_round() const;

    private:
        bool quit_;
        int damage_of_the_round_;
        Array <Location>* locations_;
        int current_location_index_;
    };
} // application

#endif //GAMESERVICE_HPP

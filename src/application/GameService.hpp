#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#include "../domain/common/Array.hpp"

namespace domain {
    class Location;
}

using namespace domain;

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

            /**
             * @brief Exits the game
             */
            void exit();

            [[nodiscard]] bool is_running() const;

            [[nodiscard]] Location& get_current_location() const;
        private:
            bool quit_;
            Array<Location>* locations_;
            int current_location_index_;
        };
}

#endif //GAMESERVICE_HPP

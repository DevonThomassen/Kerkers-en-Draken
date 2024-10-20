#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

#include "../domain/common/IPlayer.hpp"

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

            void start();
            void start(const char* file_path);
            void exit();

            [[nodiscard]] bool is_running() const;
        private:
            bool quit_;
        };
}

#endif //GAMESERVICE_HPP

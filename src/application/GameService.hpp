#ifndef GAMESERVICE_HPP
#define GAMESERVICE_HPP

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
            void start(int location_amount);

            /**
             * @brief Starts the game
             * @param file_path
             */
            void start(const char* file_path);

            /**
             * @brief Exits the game
             */
            void exit();

            [[nodiscard]] bool is_running() const;
        private:
            bool quit_;
        };
}

#endif //GAMESERVICE_HPP

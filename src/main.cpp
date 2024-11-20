#include "common/GameHandler.hpp"
#include "logger/FileLogger.hpp"

/**
 * @brief The main function of the application
 * @return The exit code
 */
int main() {
    auto logger = std::make_unique<logger::FileLogger>("output\\input.log");
    presentation::GameHandler gameHandler(std::move(logger));
    gameHandler.start();
    return 0;
}

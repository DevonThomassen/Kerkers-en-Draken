#include "common/GameHandler.hpp"
#include "logger/FileLogger.hpp"

int main() {
    auto logger = std::make_unique<logger::FileLogger>("output\\input.log");
    presentation::GameHandler gameHandler(std::move(logger));
    gameHandler.start();
    return 0;
}

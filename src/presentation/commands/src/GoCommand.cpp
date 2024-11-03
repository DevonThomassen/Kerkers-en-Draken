#include "../incl/GoCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Direction.hpp"
#include "../domain/common/Location.hpp"

presentation::commands::GoCommand::GoCommand(std::shared_ptr<GameService> game_service_)
        : game_service_(std::move(game_service_)) {}

void presentation::commands::GoCommand::execute(const std::string& arguments) {
    if (arguments == "noord") {
        game_service_->go_to_next_location(domain::Direction::North);
    } else if (arguments == "oost") {
        game_service_->go_to_next_location(domain::Direction::East);
    } else if (arguments == "zuid") {
        game_service_->go_to_next_location(domain::Direction::South);
    } else if (arguments == "west") {
        game_service_->go_to_next_location(domain::Direction::West);
    } else {
        console::error("Ongeldige richting.\n");
    }
}

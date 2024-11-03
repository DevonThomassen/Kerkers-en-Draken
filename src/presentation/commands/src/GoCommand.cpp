#include "../incl/GoCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Direction.hpp"
#include "../domain/common/Location.hpp"

presentation::commands::GoCommand::GoCommand(std::shared_ptr<GameService> game_service_)
        : game_service_(std::move(game_service_)) {}

void presentation::commands::GoCommand::execute() {
    console::print(std::format("Mogelijke richting(en): {} \n",
                               std::string(game_service_->get_current_location().get_possible_directions())));
    console::print("Waar wil je naar toe?");
    const auto direction = console::get_input();
    if (direction == "noord") {
        game_service_->go_to_next_location(domain::Direction::North);
    } else if (direction == "oost") {
        game_service_->go_to_next_location(domain::Direction::East);
    } else if (direction == "zuid") {
        game_service_->go_to_next_location(domain::Direction::South);
    } else if (direction == "west") {
        game_service_->go_to_next_location(domain::Direction::West);
    } else {
        console::error("Ongeldige richting.\n");
    }
}
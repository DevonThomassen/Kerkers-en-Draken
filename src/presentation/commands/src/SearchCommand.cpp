#include "../incl/SearchCommand.hpp"

#include "common/Console.hpp"
#include "../../../application/GameService.hpp"
#include "../../../domain/common/Location.hpp"

namespace presentation::commands {

    SearchCommand::SearchCommand(std::shared_ptr<GameService> game_service)
            : game_service_(std::move(game_service)) {}

    void SearchCommand::execute(const std::string& arguments) {
        game_service_->get_current_location().search_room();
    }

} // presentation::commands

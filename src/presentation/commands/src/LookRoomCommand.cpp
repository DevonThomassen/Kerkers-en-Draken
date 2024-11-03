#include "../incl/LookRoomCommand.hpp"

#include "../application/GameService.hpp"
#include "common/Console.hpp"
#include "../domain/common/Location.hpp"
#include "gameobject/incl/EnemyObject.hpp"

namespace presentation::commands {

    LookRoomCommand::LookRoomCommand(std::shared_ptr<GameService> game_service,
                                     std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {}

    void LookRoomCommand::execute(const std::string& arguments) {
        const auto location = game_service_->get_current_location_ptr();
        console::print(std::format("Mogelijke richting(en): {} \n",
                                   std::string(location->get_possible_directions())));

        const auto& array = location->get_objects();
        for (int i = 0; i < array.size(); i++) {
            auto object = array[i];
            if (!object->is_invisible()) {
                const auto enemy = dynamic_cast<game_objects::EnemyObject*>(object);
                if (enemy != nullptr) {
                    console::print(std::format("Vijand: {}\n", object->get_name()));
                } else {
                    console::print(std::format("Zichtbare object: {}\n", object->get_name()));
                }
            }
        }
    }

} // presentation::commands
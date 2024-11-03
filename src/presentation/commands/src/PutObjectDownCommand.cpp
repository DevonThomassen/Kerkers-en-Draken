#include "../incl/PutObjectDownCommand.hpp"

#include <memory>

#include "../../../application/GameService.hpp"
#include "common/Player.hpp"
#include "common/Console.hpp"
#include "gameobject/incl/GameObject.hpp"
#include "../domain/common/Location.hpp"

namespace presentation::commands {

    PutObjectDownCommmand::PutObjectDownCommmand(
            std::shared_ptr<GameService> game_service,
            std::unique_ptr<Player>& player)
            : game_service_(std::move(game_service)),
              player_(player) {}

    void PutObjectDownCommmand::execute(const std::string& arguments) {
        console::print("Dit zijn je objecten:\n");
        for (auto& object: player_->get_objects()) {
            console::print(std::format("{}\n", object->get_name()));
        }
        console::print("Welk object wil je neerleggen? ");
        const auto object_name = console::get_input();
        const auto object = player_->remove_object(object_name);
        if (object == nullptr) {
            console::error("Dit object heb je niet.");
            return;
        }
        game_service_->get_current_location_ptr()->add_object(object);
    }

} // presentation::commands

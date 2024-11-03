#include "GameService.hpp"
#include "../domain/filereader/FileReader.h"
#include "../domain/common/Location.hpp"
#include "../domain/common/Direction.hpp"
#include "../domain/gameobject/incl/GameObject.hpp"

namespace application {

    GameService::GameService()
            : quit_(true),
              damage_of_the_round_(0),
              locations_(nullptr),
              current_location_index_(0) {}

    GameService::~GameService() {
        delete locations_;
    }

    int GameService::start(const int location_amount) {
        // random start
        quit_ = false;
        return 0;
    }

    int GameService::start(const char* file_path) {
        locations_ = file_reader::read_file(file_path);
        quit_ = false;
        return 0;
    }

    void GameService::turn() {
        damage_of_the_round_ = get_current_location().total_damage_room();

        // move all enemies
        for (int i = 0; i < locations_->size(); i++) {
            auto location = (*locations_)[i];
            location->move_enemies();
        }
    }

    void GameService::exit() {
        quit_ = true;
    }

    bool GameService::is_running() const {
        return !quit_;
    }

    Location& GameService::get_current_location() const {
        return *((*locations_)[current_location_index_]);
    }

    bool GameService::go_to_next_location(Direction direction) {
        const auto* location = (*locations_)[current_location_index_];
        const auto new_id = location->get_exit(direction);
        if (new_id != -1) {
            for (int i = 0; i < locations_->size(); i++) {
                auto new_location = (*locations_)[i];
                if (new_location->id() == new_id) {
                    current_location_index_ = i;
                    return true;
                }
            }
        }
        return false;
    }

    Location* GameService::get_current_location_ptr() const {
        return (*locations_)[current_location_index_];
    }

    void GameService::teleport(int amount) {
        auto location = get_current_location_ptr();
        for (int i = 0; i < amount; i++) {
            location = location->get_random_exit()->destination;
        }
        for (int i = 0; i < locations_->size(); i++) {
            if ((*locations_)[i] == location) {
                current_location_index_ = i;
                return;
            }
        }
    }

    int GameService::damage_of_the_round() const {
        return damage_of_the_round_;
    }
}
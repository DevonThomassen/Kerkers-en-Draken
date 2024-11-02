#include "GameService.hpp"
#include "../domain/filereader/FileReader.h"
#include "../domain/common/Location.hpp"

namespace application {

    GameService::GameService()
            : quit_(true),
              locations_(nullptr) {}

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
        auto test = (*locations_)[1];
        quit_ = false;
        return 0;
    }

    void GameService::exit() {
        quit_ = true;
    }

    bool GameService::is_running() const {
        return !quit_;
    }
}
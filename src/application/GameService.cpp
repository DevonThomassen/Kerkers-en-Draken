#include "GameService.hpp"
#include "../domain/filereader/FileReader.h"

namespace application {

    GameService::GameService()
            : quit_(true) {}

    GameService::~GameService() {
        // delete members
    }

    void GameService::start(const int location_amount) {
        // random start
        quit_ = false;
    }

    void GameService::start(const char* file_path) {
        file_reader::read_file(file_path);
        quit_ = false;
    }

    void GameService::exit() {
        quit_ = true;
    }

    bool GameService::is_running() const {
        return !quit_;
    }
}
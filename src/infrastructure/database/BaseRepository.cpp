#include "../../domain/database/BaseRepository.hpp"

namespace repository {

    BaseRepository::BaseRepository()
            : db_(nullptr) {}

    BaseRepository::~BaseRepository() {
        sqlite3_close(db_);
    }

    int BaseRepository::open() {
        if (sqlite3_open(DEFAULT_DB_PATH, &db_) != SQLITE_OK) {
            sqlite3_close(db_);
            return 1;
        }
        return 0;
    }

    int BaseRepository::close() const {
        return sqlite3_close(db_);
    }
}
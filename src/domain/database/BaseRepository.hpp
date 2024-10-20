#ifndef BASEREPOSITORY_HPP
#define BASEREPOSITORY_HPP

#include <sqlite3.h>

#define DEFAULT_DB_PATH "kerkers_en_draken.db"

namespace repository {

    /**
     * @class BaseRepository
     * @brief Base class for all repositories
     */
    class BaseRepository {
    public:
        explicit BaseRepository();
        virtual ~BaseRepository();

    protected:
        sqlite3* db_;

        [[nodiscard]] int open();
        [[nodiscard]] int close() const;
    };
}

#endif //BASEREPOSITORY_HPP

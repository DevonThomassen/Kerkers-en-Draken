#include "../../domain/factories/DungeonFactory.h"
#include "../../domain/common/Array.hpp"
#include "../../domain/common/Location.hpp"
#include "../../domain/common/RandomEngine.hpp"
#include <iostream>

namespace factories {
    namespace constants {
        static constexpr auto DEFAULT_X = 0;
        static constexpr auto DEFAULT_Y = 0;
        static constexpr auto MIN_EXISTS = 1;
        static constexpr auto MAX_EXISTS = 4;
        static constexpr auto GRID_MIN = 20;
        static constexpr auto GRID_SIZE = 20;
        static constexpr auto START_X = 10;
        static constexpr auto START_Y = 10;
    }

    /**
     * @brief Struct to store the location and its coordinates
     */
    struct Coordinate {
        int x;
        int y;
    };

    Array<Location>* generate_dungeon(const int amount) {
        auto grid = new int[constants::GRID_SIZE][constants::GRID_SIZE];
        const auto rooms = new Coordinate[amount];

        const auto start_x = constants::START_X;
        const auto start_y = constants::START_Y;

        grid[start_x][start_y] = 1;
        rooms[0] = {start_x, start_y};
        auto room_size = 1;

        while (room_size < amount) {
            const auto current = rooms[room_size - 1];
            auto dx = 0, dy = 0;
            if (RandomEngine::get_instance().generate_random_number(0, 1) == 0) {
                dx = RandomEngine::get_instance().generate_random_number(-1, 1);
            } else {
                dy = RandomEngine::get_instance().generate_random_number(-1, 1);
            }
            if (dx == 0 && dy == 0) {
                continue;
            }
            const int new_x = current.x + dx;
            const int new_y = current.y + dy;

            if (new_x >= 0
                && new_x < constants::GRID_SIZE
                && new_y >= 0
                && new_y < constants::GRID_SIZE
                && grid[new_x][new_y] == 0) {
                grid[new_x][new_y] = room_size + 1;
                rooms[room_size++] = {new_x, new_y};
            } else {
                // check if all directions are blocked
                if ((current.x > 0
                     && grid[current.x - 1][current.y] != 0)
                    && (current.x < constants::GRID_SIZE - 1
                        && grid[current.x + 1][current.y] != 0)
                    && (current.y > 0
                        && grid[current.x][current.y - 1] != 0)
                    && (current.y < constants::GRID_SIZE - 1
                        && grid[current.x][current.y + 1] != 0)) {
                    delete[] grid;
                    delete[] rooms;
                    return nullptr;
                }
            }
        }

        const auto locations = new Array<Location>(amount);
        for (auto i = 0; i < amount; i++) {
            const auto room = rooms[i];
            locations->push_back(new Location(i, "Room", "Room location"));

        }
        locations->push_back(new Location(0, "Start", "Start location"));


        delete[] grid;
        delete[] rooms;
        return new Array<Location>(amount);
    }

}
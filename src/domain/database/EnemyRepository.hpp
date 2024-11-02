#ifndef ENEMYREPOSITORY_HPP
#define ENEMYREPOSITORY_HPP

#include "BaseRepository.hpp"
#include "../../domain/gameobject/incl/EnemyObject.hpp"

namespace repository {

    /**
     * @class EnemyRepository
     * @brief Repository for enemy data
     */
    class EnemyRepository final : public BaseRepository {
    public:
        explicit EnemyRepository();
        game_objects::EnemyObject* get_enemy(int id);
        game_objects::EnemyObject* get_enemy(const char* name);
    };

}

#endif //ENEMYREPOSITORY_HPP

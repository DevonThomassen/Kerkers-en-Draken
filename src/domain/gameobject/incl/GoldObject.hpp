#ifndef GOLDOBJECT_HPP
#define GOLDOBJECT_HPP

#include "GameObject.hpp"

namespace game_objects {
    /**
     * @class GoldObject
     * @brief A class that represents a gold object in the game.
     */
    class GoldObject final : public GameObject {
    public:
        explicit GoldObject(const char* name, const char* description, int amount);
        GoldObject(const GoldObject& other);
        GoldObject(GoldObject&& other) noexcept;
        GoldObject& operator=(const GoldObject& other);
        GoldObject& operator=(GoldObject&& other) noexcept;
        ~GoldObject() override = default;

    private:
        int amount_;
    };
}

#endif //GOLDOBJECT_HPP

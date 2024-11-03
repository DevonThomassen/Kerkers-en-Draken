#ifndef ARMOUROBJECT_HPP
#define ARMOUROBJECT_HPP

#include "GameObject.hpp"

namespace game_objects {
    /**
     * @class ArmourObject
     * @brief A class that represents an armour object in the game.
     */
    class ArmourObject final : public GameObject {
    public:
        explicit ArmourObject(const char* name, const char* description, int protection, bool invisible = false);
        ArmourObject(const ArmourObject& other);
        ArmourObject(ArmourObject&& other) noexcept;
        ArmourObject& operator=(const ArmourObject& other);
        ArmourObject& operator=(ArmourObject&& other) noexcept;
        ~ArmourObject() override;

        /**
         * @brief Returns the protection of the armour.
         * @return The protection of the armour.
         */
        [[nodiscard]] int protection() const;

    private:
        int protection_;
    };
}
#endif //ARMOUROBJECT_HPP

#include "../incl/ArmourObject.hpp"

namespace game_objects {

    ArmourObject::ArmourObject(const char* name, const char* description, const int protection, const bool invisible)
            : GameObject(name, description, invisible),
              protection_(protection) {}

    int ArmourObject::protection() const {
        return protection_;
    }

    ArmourObject::ArmourObject(const ArmourObject& other) = default;
    ArmourObject::ArmourObject(ArmourObject&& other) noexcept = default;
    ArmourObject& ArmourObject::operator=(const ArmourObject& other) = default;
    ArmourObject& ArmourObject::operator=(ArmourObject&& other) noexcept = default;
    ArmourObject::~ArmourObject() = default;
}

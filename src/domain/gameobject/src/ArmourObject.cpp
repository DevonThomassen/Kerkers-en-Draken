#include "../incl/ArmourObject.hpp"

namespace game_objects {

    ArmourObject::ArmourObject(const char* name, const char* description, int protection)
            : GameObject(name, description), _protection(protection) {}

    ArmourObject::ArmourObject(const ArmourObject& other) = default;
    ArmourObject::ArmourObject(ArmourObject&& other) noexcept = default;
    ArmourObject& ArmourObject::operator=(const ArmourObject& other) = default;
    ArmourObject& ArmourObject::operator=(ArmourObject&& other) noexcept = default;
    ArmourObject::~ArmourObject() = default;
}

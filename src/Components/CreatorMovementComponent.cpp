#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* Ogreman::CreatorMovementComponent::CreatorSpecificComponent() {
    return new Ogreman::MovementComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMovementComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::MovementComponent* mc = static_cast<Ogreman::MovementComponent*>(c);

    return mc->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMovementComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Copied InitComponent " };
}

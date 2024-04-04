#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* Ogreman::CreatorMovementComponent::CreatorSpecificComponent() {
    return new Ogreman::MovementComponent();
}

void Ogreman::CreatorMovementComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::MovementComponent* mc = static_cast<Ogreman::MovementComponent*>(c);

    if (!mc->InitComponent()) {
        // Gestion de error
    }
}

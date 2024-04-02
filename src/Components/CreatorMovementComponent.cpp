#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* Ogreman::CreatorMovementComponent::CreatorSpecificComponent() {
    Ogreman::MovementComponent* mc = new Ogreman::MovementComponent();

    if (!mc->InitComponent())
        return nullptr;
    else 
        return mc;
}

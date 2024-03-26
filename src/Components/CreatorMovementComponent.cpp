#include "CreatorMovementComponent.h"
#include "MovementComponent.h"

VeryReal::Component* VeryReal::CreatorMovementComponent::CreatorSpecificComponent() {
    MovementComponent* mc = new MovementComponent();

    if (!mc->InitComponent())
        return nullptr;
    else 
        return mc;
}

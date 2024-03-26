#include "CreatorPlayerInputComponent.h"
#include "PlayerInputComponent.h"

VeryReal::Component* VeryReal::CreatorPlayerInputComponent::CreatorSpecificComponent() {
    PlayerInputComponent* pi = new PlayerInputComponent();

    if (!pi->InitComponent())
        return nullptr;
    else
        return pi;
}

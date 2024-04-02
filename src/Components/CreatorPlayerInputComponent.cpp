#include "CreatorPlayerInputComponent.h"
#include "PlayerInputComponent.h"

VeryReal::Component* Ogreman::CreatorPlayerInputComponent::CreatorSpecificComponent() {
    Ogreman::PlayerInputComponent* pi = new Ogreman::PlayerInputComponent();

    if (!pi->InitComponent())
        return nullptr;
    else
        return pi;
}

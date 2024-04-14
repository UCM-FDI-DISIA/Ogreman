#include "CreatorPlayerInputComponent.h"
#include "PlayerInputComponent.h"

VeryReal::Component* Ogreman::CreatorPlayerInputComponent::CreatorSpecificComponent() {
    return new PlayerInputComponent();
}

void Ogreman::CreatorPlayerInputComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::PlayerInputComponent* pi = static_cast<Ogreman::PlayerInputComponent*>(c);

    if (!pi->InitComponent()) {
        // Gestion de error
    }
}

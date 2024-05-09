#include "CreatorPlayerInputComponent.h"
#include "PlayerInputComponent.h"

VeryReal::Component* Ogreman::CreatorPlayerInputComponent::CreatorSpecificComponent() {
    return new PlayerInputComponent();
}

std::pair<bool, std::string> Ogreman::CreatorPlayerInputComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::PlayerInputComponent* pi = static_cast<Ogreman::PlayerInputComponent*>(c);

    return pi->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorPlayerInputComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return{ true, "Copied InitComponent" };
}

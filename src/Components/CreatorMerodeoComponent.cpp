#include "CreatorMerodeoComponent.h"
#include "MerodeoMovementComponent.h"

VeryReal::Component* Ogreman::CreatorMerodeoComponent::CreatorSpecificComponent() {
    return new Ogreman::MerodeoMovementComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMerodeoComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::MerodeoMovementComponent* mc = static_cast<Ogreman::MerodeoMovementComponent*>(c);

    return mc->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMerodeoComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true," " };
}

#include "CreatorSmokeComponent.h"
#include "SmokeComponent.h"

VeryReal::Component* Ogreman::CreatorSmokeComponent::CreatorSpecificComponent() {
    return new Ogreman::SmokeComponent();
}

std::pair<bool, std::string> Ogreman::CreatorSmokeComponent::SpecificInitComponent(VeryReal::Component* c) {
    return static_cast<Ogreman::SmokeComponent*>(c)->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorSmokeComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return static_cast<Ogreman::SmokeComponent*>(c)->InitComponent();
}

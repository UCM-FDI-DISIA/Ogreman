#include "CreatorPickUpComponent.h"
#include "PickUpComponent.h"

VeryReal::Component* Ogreman::CreatorPickUpComponent::CreatorSpecificComponent() {
    return new PickUpComponent();
}

std::pair<bool, std::string> Ogreman::CreatorPickUpComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::PickUpComponent* pick_comp = static_cast<Ogreman::PickUpComponent*>(c);

    return pick_comp->InitComponent();
        
}

std::pair<bool, std::string> Ogreman::CreatorPickUpComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, " " };
}
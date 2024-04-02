#include "CreatorPickUpComponent.h"
#include "PickUpComponent.h"

VeryReal::Component* VeryReal::CreatorPickUpComponent::CreatorSpecificComponent() {
    PickUpComponent* pick_comp = new PickUpComponent();

    if (!pick_comp->InitComponent())
        return nullptr;
    else
        return pick_comp;
}
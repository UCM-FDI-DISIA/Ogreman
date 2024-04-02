#include "CreatorPickUpComponent.h"
#include "PickUpComponent.h"

VeryReal::Component* VeryReal::CreatorPickUpComponent::CreatorSpecificComponent() {
    PickUpComponent* mc = new PickUpComponent();

    if (!mc->InitComponent())
        return nullptr;
    else
        return mc;
}
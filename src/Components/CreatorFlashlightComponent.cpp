#include "CreatorFlashlightComponent.h"
#include "FlashlightComponent.h"

VeryReal::Component* Ogreman::CreatorFlashlightComponent::CreatorSpecificComponent() {
    Ogreman::FlashlightComponent* fl = new Ogreman::FlashlightComponent();

    if (!fl->InitComponent())
        return nullptr;
    else
        return fl;
}

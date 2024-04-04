#include "CreatorFlashlightComponent.h"
#include "FlashlightComponent.h"

VeryReal::Component* Ogreman::CreatorFlashlightComponent::CreatorSpecificComponent() {
    return new Ogreman::FlashlightComponent();
}

void Ogreman::CreatorFlashlightComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::FlashlightComponent* fl = static_cast<Ogreman::FlashlightComponent*>(c);

    if (!fl->InitComponent()) {
        // Gestion de error
    }
}

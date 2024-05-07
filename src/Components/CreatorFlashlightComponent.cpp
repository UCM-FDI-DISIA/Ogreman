#include "CreatorFlashlightComponent.h"
#include "FlashlightComponent.h"

VeryReal::Component* Ogreman::CreatorFlashlightComponent::CreatorSpecificComponent() {
    return new FlashlightComponent();
}

std::pair<bool,std::string> Ogreman::CreatorFlashlightComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::FlashlightComponent* fl = static_cast<Ogreman::FlashlightComponent*>(c);
    return fl->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorFlashlightComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return {true,"Copied Init"}
}

#include "CreatorControlsButtonComponent.h"
#include "ControlsButtonComponent.h"

VeryReal::Component* Ogreman::CreatorControlsButtonComponent::CreatorSpecificComponent()
{
    return new ControlsButtonComponent();
}

std::pair<bool, std::string> Ogreman::CreatorControlsButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::ControlsButtonComponent* controlsbutton_comp = static_cast<Ogreman::ControlsButtonComponent*>(c);

    return controlsbutton_comp->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorControlsButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Copied InitComponent" };
}
#include "CreatorControlsButtonComponent.h"
#include "ControlsButtonComponent.h"

VeryReal::Component* Ogreman::CreatorControlsButtonComponent::CreatorSpecificComponent()
{
    return new ControlsButtonComponent();
}

void Ogreman::CreatorControlsButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::ControlsButtonComponent* controlsbutton_comp = static_cast<Ogreman::ControlsButtonComponent*>(c);

    if (!controlsbutton_comp->InitComponent()) {

    }
}

void Ogreman::CreatorControlsButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
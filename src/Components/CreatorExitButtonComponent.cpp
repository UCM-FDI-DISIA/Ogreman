#include "CreatorExitButtonComponent.h"
#include "ExitButtonComponent.h"

VeryReal::Component* Ogreman::CreatorExitButtonComponent::CreatorSpecificComponent()
{
	return new ExitButtonComponent();
}

void Ogreman::CreatorExitButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::ExitButtonComponent* exitbutton_comp = static_cast<Ogreman::ExitButtonComponent*>(c);

    if (!exitbutton_comp->InitComponent()) {

    }
}

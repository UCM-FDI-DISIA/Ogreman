#include "CreatorExitButtonComponent.h"
#include "ExitButtonComponent.h"

VeryReal::Component* Ogreman::CreatorExitButtonComponent::CreatorSpecificComponent()
{
	return new ExitButtonComponent();
}

std::pair<bool, std::string> Ogreman::CreatorExitButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::ExitButtonComponent* exitbutton_comp = static_cast<Ogreman::ExitButtonComponent*>(c);

	return exitbutton_comp->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorExitButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, "" };
}

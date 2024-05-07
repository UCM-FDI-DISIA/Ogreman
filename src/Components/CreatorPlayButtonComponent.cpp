#include "CreatorPlayButtonComponent.h"
#include "PlayButtonComponent.h"

VeryReal::Component* Ogreman::CreatorPlayButtonComponent::CreatorSpecificComponent()
{
	return new PlayButtonComponent();
}

std::pair<bool, std::string> Ogreman::CreatorPlayButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::PlayButtonComponent* playbutton_comp = static_cast<Ogreman::PlayButtonComponent*>(c);
	return playbutton_comp->InitComponent();
}
std::pair<bool, std::string> Ogreman::CreatorPlayButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, " " };
}


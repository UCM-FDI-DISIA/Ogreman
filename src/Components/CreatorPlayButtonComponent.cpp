#include "CreatorPlayButtonComponent.h"
#include "PlayButtonComponent.h"

VeryReal::Component* Ogreman::CreatorPlayButtonComponent::CreatorSpecificComponent()
{
	return new PlayButtonComponent();
}

void Ogreman::CreatorPlayButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::PlayButtonComponent* playbutton_comp = static_cast<Ogreman::PlayButtonComponent*>(c);

    if (!playbutton_comp->InitComponent()) {
       
    }
}

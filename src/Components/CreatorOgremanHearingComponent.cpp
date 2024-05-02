#include "CreatorOgremanHearingComponent.h"
#include "OgremanHearingComponent.h"

VeryReal::Component* Ogreman::CreatorOgremanHearingComponent::CreatorSpecificComponent()
{
	return new OgremanHearingComponent();
}

void Ogreman::CreatorOgremanHearingComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::OgremanHearingComponent* ogrehearing = static_cast<Ogreman::OgremanHearingComponent*>(c);

    if (!ogrehearing->InitComponent()) {
        // Gestion de error
    }
}
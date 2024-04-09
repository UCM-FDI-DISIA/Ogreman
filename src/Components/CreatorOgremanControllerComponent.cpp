#include "CreatorOgremanControllerComponent.h"
#include "OgremanControllerComponent.h"
VeryReal::Component* CreatorOgremanControllerComponent::CreatorSpecificComponent() {
	return new Ogreman::OgremanControllerComponent();
}
void SpecificInitComponent(VeryReal::Component* c) {
	Ogreman::OgremanControllerComponent* com = static_cast<Ogreman::OgremanControllerComponent*>(c);
	bool b = com->InitComponent();

	if (!b) {

	}
	


}
#include "CreatorOgremanControllerComponent.h"
#include "OgremanControllerComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanControllerComponent::CreatorSpecificComponent() {
	return new Ogreman::OgremanControllerComponent();
}
void Ogreman::CreatorOgremanControllerComponent::SpecificInitComponent(VeryReal::Component* c) {
	Ogreman::OgremanControllerComponent* com = static_cast<Ogreman::OgremanControllerComponent*>(c);
	bool b = com->InitComponent();

	if (!b) {

	}
	


}
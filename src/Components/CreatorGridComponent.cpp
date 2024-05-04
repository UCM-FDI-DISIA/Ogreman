#include "CreatorGridComponent.h"
#include "GridComponent.h"

VeryReal::Component* Ogreman::CreatorGridComponent::CreatorSpecificComponent() {
	return new Ogreman::GridComponent();
}
void Ogreman::CreatorGridComponent::SpecificInitComponent(VeryReal::Component* c)  {
	Ogreman::GridComponent* grid = static_cast<Ogreman::GridComponent*>(c);
	bool b=grid->InitComponent();
	if (!b) {

	}
}

void Ogreman::CreatorGridComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
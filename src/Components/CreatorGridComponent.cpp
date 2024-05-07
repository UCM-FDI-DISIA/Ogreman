#include "CreatorGridComponent.h"
#include "GridComponent.h"

VeryReal::Component* Ogreman::CreatorGridComponent::CreatorSpecificComponent() {
	return new Ogreman::GridComponent();
}
std::pair<bool,std::string> Ogreman::CreatorGridComponent::SpecificInitComponent(VeryReal::Component* c)  {
	Ogreman::GridComponent* grid = static_cast<Ogreman::GridComponent*>(c);
	return grid->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorGridComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, "Copied InitComponent" };
}
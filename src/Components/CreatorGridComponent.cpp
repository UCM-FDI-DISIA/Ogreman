#include "CreatorGridComponent.h"
#include "GridComponent.h"
VeryReal::Component* CreatorSpecificComponent() {
	return new Ogreman::GridComponent();
}
void SpecificInitComponent(VeryReal::Component* c)  {
	Ogreman::GridComponent* grid = static_cast<Ogreman::GridComponent*>(c);
	bool b=grid->InitComponent();
	if (!b) {


	}

}
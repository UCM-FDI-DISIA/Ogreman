#include "CreatorGridComponent.h"
#include "GridComponent.h"
VeryReal::Component* CreatorSpecificComponent() {
	return new GridComponent();
}
void SpecificInitComponent(VeryReal::Component* c)  {
	GridComponent* grid = static_cast<GridComponent*>(c);
	bool b=grid->InitComponent();
	if (!b) {


	}

}
#include "CreatorCellComponent.h"
#include "CellComponent.h"

VeryReal::Component* Ogreman::CreatorCellComponent::CreatorSpecificComponent() {
    return new Ogreman::CellComponent();
}

void Ogreman::CreatorCellComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::CellComponent* cell_comp = static_cast<Ogreman::CellComponent*>(c);

    if (!cell_comp->InitComponent()) {
        // Gestion de errror
    }    
}

void Ogreman::CreatorCellComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    
}
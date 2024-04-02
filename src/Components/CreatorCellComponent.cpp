#include "CreatorCellComponent.h"
#include "CellComponent.h"

VeryReal::Component* VeryReal::CreatorCellComponent::CreatorSpecificComponent() {
    CellComponent* cell_comp = new CellComponent();

    if (!cell_comp->InitComponent())
        return nullptr;
    else
        return cell_comp;
}
#include "CreatorCellComponent.h"
#include "CellComponent.h"

VeryReal::Component* Ogreman::CreatorCellComponent::CreatorSpecificComponent() {
    return new Ogreman::CellComponent();
}

std::pair<bool, std::string> Ogreman::CreatorCellComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::CellComponent* cell_comp = static_cast<Ogreman::CellComponent*>(c);
    return cell_comp->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorCellComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "Copied InitComponent" };
}
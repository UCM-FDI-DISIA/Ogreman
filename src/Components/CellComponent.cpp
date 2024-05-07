#include "CellComponent.h"
std::pair<bool, std::string> Ogreman::CellComponent::InitComponent() {
	pickedUp = false;
	return { true, "CellComponent Inicialize" };
}
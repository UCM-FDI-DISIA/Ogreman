#include "CreatorNNotesComponent.h"
#include "NNotesComponent.h"

VeryReal::Component* Ogreman::CreatorNNotesComponent::CreatorSpecificComponent() {
    return new NNotesComponent();
}

void Ogreman::CreatorNNotesComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::NNotesComponent* note_comp = static_cast<Ogreman::NNotesComponent*>(c);
	int notes, totalnotas;
	if (std::holds_alternative<int>(parameters_map.at("notes")->GetVariant())) {
		notes = std::get<int>(parameters_map.at("notes")->GetVariant());
	}
	if (std::holds_alternative<int>(parameters_map.at("totalnotas")->GetVariant())) {
		totalnotas = std::get<int>(parameters_map.at("totalnotas")->GetVariant());
	}
	bool b = note_comp->InitComponent(notes, totalnotas);
	if (!b) {

	}
	
}

void Ogreman::CreatorNNotesComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
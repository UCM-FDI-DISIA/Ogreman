#include "CreatorNoteComponent.h"
#include "NoteComponent.h"

VeryReal::Component* Ogreman::CreatorNoteComponent::CreatorSpecificComponent() {
    return new NoteComponent();
}

void Ogreman::CreatorNoteComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::NoteComponent* note_comp = static_cast<Ogreman::NoteComponent*>(c);
	std::string text;
	if (std::holds_alternative<std::string>(parameters_map.at("text")->GetVariant())) {
		text = std::get<std::string>(parameters_map.at("text")->GetVariant());
	}
	bool b = note_comp->InitComponent(text);
	if (!b) {

	}
	
}

void Ogreman::CreatorNoteComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
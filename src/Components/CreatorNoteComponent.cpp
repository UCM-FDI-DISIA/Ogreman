#include "CreatorNoteComponent.h"
#include "NoteComponent.h"

VeryReal::Component* Ogreman::CreatorNoteComponent::CreatorSpecificComponent() {
    return new NoteComponent();
}

void Ogreman::CreatorNoteComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::NoteComponent* note_comp = static_cast<Ogreman::NoteComponent*>(c);
	std::string text;

#pragma region Text

	if (parameters_map.find("text") != parameters_map.end()) {
		if (std::holds_alternative<std::string>(parameters_map.at("text")->GetVariant())) {
			text = std::get<std::string>(parameters_map.at("text")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para text este sera seteado por defecto" << std::endl;
			text = "";
		}
	}
	else {
		std::cout << "No existe ningun parametro text este sera seteado por defecto" << std::endl;
		text = "";
	}
#pragma endregion
	bool b = note_comp->InitComponent(text);
	if (!b) {

	}
	
}

void Ogreman::CreatorNoteComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
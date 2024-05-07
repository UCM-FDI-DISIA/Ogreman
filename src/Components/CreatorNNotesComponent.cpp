#include "CreatorNNotesComponent.h"
#include "NNotesComponent.h"

VeryReal::Component* Ogreman::CreatorNNotesComponent::CreatorSpecificComponent() {
    return new NNotesComponent();
}

std::pair<bool, std::string>  Ogreman::CreatorNNotesComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::NNotesComponent* note_comp = static_cast<Ogreman::NNotesComponent*>(c);
	int notes, totalnotas;
	
	
#pragma region notes

	if (parameters_map.find("notes") != parameters_map.end()) {
		if (std::holds_alternative<int>(parameters_map.at("notes")->GetVariant())) {
			notes = std::get<int>(parameters_map.at("notes")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para notes este sera seteado por defecto" << std::endl;
			notes = 0;
		}
	}
	else {
		std::cout << "No existe ningun parametro notes este sera seteado por defecto" << std::endl;
		notes = 0;
	}
#pragma endregion
#pragma region totalnotes

	if (parameters_map.find("totalnotas") != parameters_map.end()) {
		if (std::holds_alternative<int>(parameters_map.at("totalnotas")->GetVariant())) {
			totalnotas = std::get<int>(parameters_map.at("totalnotas")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para ttoshow este sera seteado por defecto" << std::endl;
			totalnotas = 4;
		}
	}
	else {
		std::cout << "No existe ningun parametro ttoshow este sera seteado por defecto" << std::endl;
		totalnotas = 4;
	}
#pragma endregion
	return note_comp->InitComponent(notes, totalnotas);
}

std::pair<bool, std::string>  Ogreman::CreatorNNotesComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, "" };
}
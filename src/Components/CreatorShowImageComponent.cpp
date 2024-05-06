#include "CreatorShowImageComponent.h"
#include "ShowImageComponent.h"

VeryReal::Component* Ogreman::CreatorShowImageComponent::CreatorSpecificComponent() {
    return new ShowImageComponent();
}

void Ogreman::CreatorShowImageComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::ShowImageComponent* showImage_comp = static_cast<Ogreman::ShowImageComponent*>(c);
    float ttoshow;
#pragma region TimeShow

	if (parameters_map.find("ttoshow") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("ttoshow")->GetVariant())) {
			ttoshow = std::get<float>(parameters_map.at("ttoshow")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para ttoshow este sera seteado por defecto" << std::endl;
			ttoshow = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro ttoshow este sera seteado por defecto" << std::endl;
		ttoshow = 1;
	}
#pragma endregion
   
    bool b = showImage_comp->InitComponent(ttoshow);
    if (!b) {
        // Gestion de error
    }
}

void Ogreman::CreatorShowImageComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
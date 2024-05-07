#include "CreatorRangosVisionComponent.h"
#include "RangosVisionComponent.h"

VeryReal::Component* Ogreman::CreatorRangosVisionComponent::CreatorSpecificComponent() {
	return new RangosVisionComponent();
}
std::pair<bool, std::string>  Ogreman::CreatorRangosVisionComponent::SpecificInitComponent(VeryReal::Component* c) {
	RangosVisionComponent* ranvision = static_cast<RangosVisionComponent*>(c);

	float  maxv, minv, maxt, mint;
	int id;

#pragma region MaxV

	if (parameters_map.find("maxv") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("maxv")->GetVariant())) {
			maxv = std::get<float>(parameters_map.at("maxv")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para maxv este sera seteado por defecto" << std::endl;
			maxv = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro maxv este sera seteado por defecto" << std::endl;
		maxv = 1;
	}
#pragma endregion

#pragma region MinV

	if (parameters_map.find("minv") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("minv")->GetVariant())) {
			minv = std::get<float>(parameters_map.at("minv")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para minv este sera seteado por defecto" << std::endl;
			minv = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro minv este sera seteado por defecto" << std::endl;
		minv = 1;
	}
#pragma endregion

#pragma region MaxT

	if (parameters_map.find("maxt") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("maxt")->GetVariant())) {
			maxt = std::get<float>(parameters_map.at("maxt")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para maxt este sera seteado por defecto" << std::endl;
			maxt = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro maxt este sera seteado por defecto" << std::endl;
		maxt = 1;
	}
#pragma endregion


#pragma region MinT

	if (parameters_map.find("mint") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("mint")->GetVariant())) {
			mint = std::get<float>(parameters_map.at("mint")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para mint este sera seteado por defecto" << std::endl;
			mint = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro mint este sera seteado por defecto" << std::endl;
		mint = 1;
	}
#pragma endregion
	return ranvision->InitComponent(maxv, minv, maxt, mint);
}
	

std::pair<bool, std::string>  Ogreman::CreatorRangosVisionComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, " " };
}
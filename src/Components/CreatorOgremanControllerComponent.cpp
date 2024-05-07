#include "CreatorOgremanControllerComponent.h"
#include "OgremanControllerComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanControllerComponent::CreatorSpecificComponent() {
	return new Ogreman::OgremanControllerComponent();
}
std::pair<bool, std::string> Ogreman::CreatorOgremanControllerComponent::SpecificInitComponent(VeryReal::Component* c) {
	Ogreman::OgremanControllerComponent* com = static_cast<Ogreman::OgremanControllerComponent*>(c);

	float  alignmentWeight, cohesionWeight, separationWeight, maxSpeed, separationDistance, min_dist_follow,max_dist_follow;

#pragma region AlignmentWeight

	if (parameters_map.find("alignmentWeight") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("alignmentWeight")->GetVariant())) {
			alignmentWeight = std::get<float>(parameters_map.at("alignmentWeight")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para alignmentWeight este sera seteado por defecto" << std::endl;
			alignmentWeight = 0.1;
		}
	}
	else {
		std::cout << "No existe ningun parametro alignmentWeight este sera seteado por defecto" << std::endl;
		alignmentWeight = 0.1;
	}
#pragma endregion

#pragma region CohesionWeight

	if (parameters_map.find("cohesionWeight") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("cohesionWeight")->GetVariant())) {
			cohesionWeight = std::get<float>(parameters_map.at("cohesionWeight")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para cohesionWeight este sera seteado por defecto" << std::endl;
			cohesionWeight = 0.1;
		}
	}
	else {
		std::cout << "No existe ningun parametro cohesionWeight este sera seteado por defecto" << std::endl;
		cohesionWeight = 0.1;
	}
#pragma endregion

#pragma region SeparationWeight

	if (parameters_map.find("separationWeight") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("separationWeight")->GetVariant())) {
			separationWeight = std::get<float>(parameters_map.at("separationWeight")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para separationWeight este sera seteado por defecto" << std::endl;
			separationWeight = 0.1;
		}
	}
	else {
		std::cout << "No existe ningun parametro separationWeight este sera seteado por defecto" << std::endl;
		separationWeight = 0.1;
	}
#pragma endregion
#pragma region MaxSpeed

	if (parameters_map.find("maxSpeed") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("maxSpeed")->GetVariant())) {
			maxSpeed = std::get<float>(parameters_map.at("maxSpeed")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para maxSpeed este sera seteado por defecto" << std::endl;
			maxSpeed = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro maxSpeed este sera seteado por defecto" << std::endl;
		maxSpeed = 1;
	}
#pragma endregion
#pragma region SeparationDistance

	if (parameters_map.find("separationDistance") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("separationDistance")->GetVariant())) {
			separationDistance = std::get<float>(parameters_map.at("separationDistance")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para separationDistance este sera seteado por defecto" << std::endl;
			separationDistance = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro separationDistance este sera seteado por defecto" << std::endl;
		separationDistance = 1;
	}
#pragma endregion

#pragma region MinDistFollow

	if (parameters_map.find("min_dist_follow") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("min_dist_follow")->GetVariant())) {
			min_dist_follow = std::get<float>(parameters_map.at("min_dist_follow")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para min_dist_follow este sera seteado por defecto" << std::endl;
			min_dist_follow = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro min_dist_follow este sera seteado por defecto" << std::endl;
		min_dist_follow = 1;
	}
#pragma endregion
#pragma region MaxDistFollow

	if (parameters_map.find("max_dist_follow") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("max_dist_follow")->GetVariant())) {
			max_dist_follow = std::get<float>(parameters_map.at("max_dist_follow")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para max_dist_follow este sera seteado por defecto" << std::endl;
			max_dist_follow = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro max_dist_follow este sera seteado por defecto" << std::endl;
		max_dist_follow = 1;
	}
#pragma endregion
	return com->InitComponent(alignmentWeight,cohesionWeight,separationWeight,maxSpeed,separationDistance,min_dist_follow,max_dist_follow);
}

std::pair<bool, std::string> Ogreman::CreatorOgremanControllerComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return { true, "" };
}
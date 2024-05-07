#include "CreatorNodeComponent.h"
#include "NodeComponent.h"

VeryReal::Component* Ogreman::CreatorNodeComponent::CreatorSpecificComponent() {
	return new NodeComponent();
}
std::pair<bool, std::string> Ogreman::CreatorNodeComponent::SpecificInitComponent(VeryReal::Component* c) {
	NodeComponent* nodecom=static_cast<NodeComponent*>(c);
	bool ispatrol,iswalkable;
	float cost,hcost;
	int id;

#pragma region IsPatrol

	if (parameters_map.find("ispatrol") != parameters_map.end()) {
		if (std::holds_alternative<bool>(parameters_map.at("ispatrol")->GetVariant())) {
			ispatrol = std::get<bool>(parameters_map.at("ispatrol")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para ispatrol este sera seteado por defecto" << std::endl;
			ispatrol = false;
		}
	}
	else {
		std::cout << "No existe ningun parametro ispatrol este sera seteado por defecto" << std::endl;
		ispatrol = false;
	}
#pragma endregion

#pragma region IsWalkable

	if (parameters_map.find("iswalkable") != parameters_map.end()) {
		if (std::holds_alternative<bool>(parameters_map.at("iswalkable")->GetVariant())) {
			iswalkable = std::get<bool>(parameters_map.at("iswalkable")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para iswalkable este sera seteado por defecto" << std::endl;
			iswalkable = false;
		}
	}
	else {
		std::cout << "No existe ningun parametro iswalkable este sera seteado por defecto" << std::endl;
		iswalkable = false;
	}
#pragma endregion

#pragma region Cost

	if (parameters_map.find("cost") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("cost")->GetVariant())) {
			cost = std::get<float>(parameters_map.at("cost")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para cost este sera seteado por defecto" << std::endl;
			cost = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro cost este sera seteado por defecto" << std::endl;
		cost = 1;
	}
#pragma endregion

#pragma region HCost

	if (parameters_map.find("hcost") != parameters_map.end()) {
		if (std::holds_alternative<float>(parameters_map.at("hcost")->GetVariant())) {
			hcost = std::get<float>(parameters_map.at("hcost")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para hcost este sera seteado por defecto" << std::endl;
			hcost = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro hcost este sera seteado por defecto" << std::endl;
		hcost = 1;
	}
#pragma endregion

#pragma region ID

	if (parameters_map.find("id") != parameters_map.end()) {
		if (std::holds_alternative<int>(parameters_map.at("id")->GetVariant())) {
			id = std::get<int>(parameters_map.at("id")->GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para id este sera seteado por defecto" << std::endl;
			id = 1;
		}
	}
	else {
		std::cout << "No existe ningun parametro id este sera seteado por defecto" << std::endl;
		id = 1;
	}
#pragma endregion
	 return nodecom->InitComponent(ispatrol,cost,hcost,iswalkable,id);
}

std::pair<bool, std::string> Ogreman::CreatorNodeComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
	return{ true,"Copied InitComponent " };
}
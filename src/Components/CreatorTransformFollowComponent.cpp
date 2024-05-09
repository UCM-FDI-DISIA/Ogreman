#include "CreatorTransformFollowComponent.h"
#include "TransformFollowComponent.h"

VeryReal::Component* Ogreman::CreatorTransformFollowComponent::CreatorSpecificComponent()
{
	return new TransformFollowComponent;
}

std::pair<bool, std::string> Ogreman::CreatorTransformFollowComponent::SpecificInitComponent(VeryReal::Component* c)
{
	Ogreman::TransformFollowComponent* transformFollow_comp = static_cast<Ogreman::TransformFollowComponent*>(c);
	std::string targetName;

#pragma region TargetName

	if (parameters_map.find("targetName") != parameters_map.end()) {
		if (std::holds_alternative<std::string>(parameters_map.at("targetName").GetVariant())) {
			targetName = std::get<std::string>(parameters_map.at("targetName").GetVariant());
		}
		else {
			std::cout << "No se ha especificado ningun valor para ttoshow este sera seteado por defecto" << std::endl;
			targetName = "";
		}
	}
	else {
		std::cout << "No existe ningun parametro ttoshow este sera seteado por defecto" << std::endl;
		targetName = "";
	}
#pragma endregion

	return transformFollow_comp->InitComponent(targetName);
}

std::pair<bool, std::string> Ogreman::CreatorTransformFollowComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other)
{
	return{ true, "" };
}
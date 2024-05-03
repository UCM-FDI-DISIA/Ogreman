#include "CreatorOgremanControllerComponent.h"
#include "OgremanControllerComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanControllerComponent::CreatorSpecificComponent() {
	return new Ogreman::OgremanControllerComponent();
}
void Ogreman::CreatorOgremanControllerComponent::SpecificInitComponent(VeryReal::Component* c) {
	Ogreman::OgremanControllerComponent* com = static_cast<Ogreman::OgremanControllerComponent*>(c);

	float  alignmentWeight, cohesionWeight, separationWeight, maxSpeed, separationDistance;

	if (std::holds_alternative<float>(parameters_map.at("alignmentWeight")->GetVariant())) {
		alignmentWeight = std::get<float>(parameters_map.at("alignmentWeight")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("cohesionWeight")->GetVariant())) {
		cohesionWeight = std::get<float>(parameters_map.at("cohesionWeight")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("separationWeight")->GetVariant())) {
		separationWeight = std::get<float>(parameters_map.at("separationWeight")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("maxSpeed")->GetVariant())) {
		maxSpeed = std::get<float>(parameters_map.at("maxSpeed")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("separationDistance")->GetVariant())) {
		separationDistance = std::get<float>(parameters_map.at("separationDistance")->GetVariant());
	}


	bool b = com->InitComponent(alignmentWeight,cohesionWeight,separationWeight,maxSpeed,separationDistance);

	if (!b) {

	}
	


}
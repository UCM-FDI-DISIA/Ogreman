#include "CreatorOgremanControllerComponent.h"
#include "OgremanControllerComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanControllerComponent::CreatorSpecificComponent() {
	return new Ogreman::OgremanControllerComponent();
}
void Ogreman::CreatorOgremanControllerComponent::SpecificInitComponent(VeryReal::Component* c) {
	Ogreman::OgremanControllerComponent* com = static_cast<Ogreman::OgremanControllerComponent*>(c);

	float  alignmentWeight, cohesionWeight, separationWeight, maxSpeed, separationDistance, min_dist_follow,max_dist_follow;

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
	if (std::holds_alternative<float>(parameters_map.at("min_dist_follow")->GetVariant())) {
		min_dist_follow = std::get<float>(parameters_map.at("min_dist_follow")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("max_dist_follow")->GetVariant())) {
		max_dist_follow = std::get<float>(parameters_map.at("max_dist_follow")->GetVariant());
	}

	bool b = com->InitComponent(alignmentWeight,cohesionWeight,separationWeight,maxSpeed,separationDistance,min_dist_follow,max_dist_follow);

	if (!b) {

	}
}

void Ogreman::CreatorOgremanControllerComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
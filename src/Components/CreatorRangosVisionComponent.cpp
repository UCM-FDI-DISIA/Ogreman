#include "CreatorRangosVisionComponent.h"
#include "RangosVisionComponent.h"

VeryReal::Component* Ogreman::CreatorRangosVisionComponent::CreatorSpecificComponent() {
	return new RangosVisionComponent();
}
void Ogreman::CreatorRangosVisionComponent::SpecificInitComponent(VeryReal::Component* c) {
	RangosVisionComponent* ranvision = static_cast<RangosVisionComponent*>(c);

	float  maxv, minv, maxt, mint;
	int id;
	if (std::holds_alternative<float>(parameters_map.at("maxv")->GetVariant())) {
		maxv = std::get<float>(parameters_map.at("maxv")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("minv")->GetVariant())) {
		minv = std::get<float>(parameters_map.at("minv")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("maxt")->GetVariant())) {
		maxt = std::get<float>(parameters_map.at("maxt")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("mint")->GetVariant())) {
		mint = std::get<float>(parameters_map.at("mint")->GetVariant());
	}
	 bool b= ranvision->InitComponent( maxv,  minv,  maxt,  mint);
	 if (!b) {

	}
}

void Ogreman::CreatorRangosVisionComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
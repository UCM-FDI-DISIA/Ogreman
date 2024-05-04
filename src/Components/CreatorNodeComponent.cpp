#include "CreatorNodeComponent.h"
#include "NodeComponent.h"

VeryReal::Component* Ogreman::CreatorNodeComponent::CreatorSpecificComponent() {
	return new NodeComponent();
}
void Ogreman::CreatorNodeComponent::SpecificInitComponent(VeryReal::Component* c) {
	NodeComponent* nodecom=static_cast<NodeComponent*>(c);
	bool ispatrol,iswalkable;
	float cost,hcost;
	int id;
	if (std::holds_alternative<bool>(parameters_map.at("ispatrol")->GetVariant())) {
		ispatrol = std::get<bool>(parameters_map.at("ispatrol")->GetVariant());
	}
	if (std::holds_alternative<bool>(parameters_map.at("iswalkable")->GetVariant())) {
		iswalkable = std::get<bool>(parameters_map.at("iswalkable")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("cost")->GetVariant())) {
		cost = std::get<float>(parameters_map.at("cost")->GetVariant());
	}
	if (std::holds_alternative<float>(parameters_map.at("hcost")->GetVariant())) {
		hcost = std::get<float>(parameters_map.at("hcost")->GetVariant());
	}
	if (std::holds_alternative<int>(parameters_map.at("id")->GetVariant())) {
		id = std::get<int>(parameters_map.at("id")->GetVariant());
	}
	 bool b=nodecom->InitComponent(ispatrol,cost,hcost,iswalkable,id);
	 if (!b) {

	}
}

void Ogreman::CreatorNodeComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
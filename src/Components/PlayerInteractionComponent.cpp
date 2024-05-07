#include "PlayerInteractionComponent.h"
#include "FlashlightComponent.h"
#include "Entity.h"

std::pair<bool, std::string>  Ogreman::PlayerInteractionComponent::InitComponent() {
	my_flashlight_component = this->GetEntity()->GetComponent<Ogreman::FlashlightComponent>();
	if (my_flashlight_component == nullptr) {
		return{ false,"FlashlightComponent isn't in this Entity, ERROR from PlayerInteractionComponent" };
	}

	return { true, " PlayerInteractionComponent was right made it" };
}

void Ogreman::PlayerInteractionComponent::GetCell()
{
	this->GetEntity()->GetComponent<Ogreman::FlashlightComponent>()->ChargeBatery(10); //la cantidad es temporal
}


#include "ShowImageComponent.h"
#include "Entity.h"
#include "UI/UItransformComponent.h"
std::pair<bool, std::string>  Ogreman::ShowImageComponent::InitComponent(double ttoshow) {
	time_toshow = ttoshow;
	active = false;
	uitr = this->GetEntity()->GetComponent<VeryReal::UITransformComponent>();
	if (uitr == nullptr) {
		return { false, "this entity doesn't have  UITransformComponent. ERROR:ShowImageComponent" };
	}
	return { true, "ShowImageComponent was made right-->InitComponent " };
}

void Ogreman::ShowImageComponent::Update(const double& dt) {
	if (active) {
		uitr->showElement();
		time_toshow -= dt;
		if (time_toshow <= 0.0) {
			active = false;
		}
	}
	else {
		uitr->hideElement();
	}
 }
void Ogreman::ShowImageComponent::activeTime() {
	active = true;
}
	
#include "ShowImageComponent.h"
#include "Entity.h"
#include "UI/UItransformComponent.h"
bool Ogreman::ShowImageComponent::InitComponent(double ttoshow) {
	time_toshow = ttoshow;
	active = false;
	uitr = this->GetEntity()->GetComponent<VeryReal::UITransformComponent>();
	if (uitr == nullptr) {
		return false;
	}
	return true;
}

void Ogreman::ShowImageComponent::Update(const double& dt) {
	if (active) {
		uitr->showElement();
		time_toshow -= dt;
		if (time_toshow <= 0.0) {
			this->GetEntity()->SetActive(false);
		}
	}
	else {
		uitr->hideElement();
	}
 }
void Ogreman::ShowImageComponent::activeTime() {
	active = true;
}
	
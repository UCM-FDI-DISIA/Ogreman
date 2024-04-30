#include "FlashlightComponent.h"
#include <algorithm>
#include "Entity.h"
#include <LightComponent.h>
#include "PlayerInputComponent.h"
#include "UI/UIProgressBarComponent.h"

bool Ogreman::FlashlightComponent::InitComponent() {
	my_input = this->GetEntity()->GetComponent<Ogreman::PlayerInputComponent>();	
	my_light_spot = this->GetEntity()->GetComponent<VeryReal::LightComponent>();
	my_progress_bar = this->GetEntity()->GetComponent<VeryReal::UIProgressBarComponent>();
	
	if (this->my_input != nullptr && this->my_light_spot != nullptr)
		return true;
	else {
		my_progress_bar->setMaximun(max_energy);
		my_progress_bar->setProgress(energy_remaining);
		return false;
	}
}

void Ogreman::FlashlightComponent::Update(const double& dt) {
	if (my_input->IsFlashLightPressed() && energy_remaining > 0.0f) {
		energy_remaining = std::max(energy_remaining - energy_consume_rate * dt, 0.0);
		my_progress_bar->setProgress(energy_remaining);
		my_light_spot->setVisible(true);
	}
	else {
		my_light_spot->setVisible(false);
	}
	//std::cout << energy_remaining << std::endl;
}

bool Ogreman::FlashlightComponent::ChargeBatery(double energy_charge) {
	if (energy_remaining == max_energy) return false;
	else {
		energy_remaining = std::min(energy_remaining + energy_charge, max_energy);
		my_progress_bar->setProgress(energy_remaining);
		return true;
	}
}
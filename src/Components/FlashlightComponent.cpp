#include "FlashlightComponent.h"
#include <algorithm>
#include "Entity.h"
#include "Light.h"
#include "PlayerInputComponent.h"

bool Ogreman::FlashlightComponent::InitComponent() {
	my_input = this->GetEntity()->GetComponent<Ogreman::PlayerInputComponent>("PlayerInputComponent");
	// GetComponent o InitComponent de la linterna
	// my_light_spot = this->GetEntity()->GetComponent<VeryReal::Light>("Light");
	
	if (this->my_input != nullptr && this->my_light_spot != nullptr)
		return true;
	else
		return false;
}

void Ogreman::FlashlightComponent::Update(const double& dt) {
	if (my_input->IsFlashLightPressed() && energy_remaining > 0.0f) {
		energy_remaining = std::max(energy_remaining - energy_consume_rate * dt, 0.0);
		// Activar linterna (setActive del nodo de ogre)
	}
	else {
		// Desactivar linterna (setActive del nodo de ogre)
	}
}

bool Ogreman::FlashlightComponent::ChargeBatery(double energy_charge) {
	if (energy_remaining == max_energy) return false;
	else {
		energy_remaining = std::min(energy_remaining + energy_charge, max_energy);
		return true;
	}
}
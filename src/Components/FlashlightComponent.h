#pragma once
#ifndef FLASHLIGHTCOMPONENT
#define FLASHLIGHTCOMPONENT
#include <Component.h>

namespace VeryReal {
	class Light;
}

namespace Ogreman {
	class PlayerInputComponent;
}

namespace Ogreman {
	class FlashlightComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void LateUpdate(const double& dt);

		bool ChargeBatery(double energy_charge);

	protected:
		double max_energy = 100.0f;
		double MAX_ENERGY = 5;
		double energy_remaining = MAX_ENERGY;
		double energy_consume_rate = 1.0f;

		Ogreman::PlayerInputComponent* my_input;
		VeryReal::Light* my_light_spot;
	};
}
#endif
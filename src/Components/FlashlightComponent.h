#pragma once
#ifndef FLASHLIGHTCOMPONENT
#define FLASHLIGHTCOMPONENT
#include <Component.h>
#include "../Export.h"

namespace VeryReal {
	class LightComponent;
	class UIProgressBarComponent;
}

namespace Ogreman {
	class PlayerInputComponent;
}

namespace Ogreman {
	class OGREMAN_API FlashlightComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		bool ChargeBatery(double energy_charge);

	protected:
		double max_energy = 100.0f;
		double MAX_ENERGY = 5;
		double energy_remaining = MAX_ENERGY;
		double energy_consume_rate = 1.0f;

		Ogreman::PlayerInputComponent* my_input;
		VeryReal::LightComponent* my_light_spot;
		VeryReal::UIProgressBarComponent* my_progress_bar;
	};
}
#endif
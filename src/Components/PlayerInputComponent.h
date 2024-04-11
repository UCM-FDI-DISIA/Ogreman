#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"
namespace VeryReal {
	class CameraComponent;
}

namespace Ogreman {
	class MovementComponent;
	class PickUpComponent;
}

namespace Ogreman {
	class OGREMAN_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		inline bool IsFlashLightPressed() { return flashlight; }

	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos;

		float audio_intensity;
		bool flashlight, canPickUp = false;

		Ogreman::MovementComponent* my_movement_component;
		Ogreman::PickUpComponent* my_pickup_component;
		VeryReal::CameraComponent* my_camera_component;
	};
}
#endif
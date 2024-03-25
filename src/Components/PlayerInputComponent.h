#pragma once
#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"

namespace VeryReal {
	class MovementComponent;
	class CameraComponent;
}

namespace VeryReal {
	class PlayerInputComponent : public Component {
	public:
		virtual void InitComponent();
		virtual void Update(const double& dt);

		inline bool IsFlashLightPressed() { return flashlight; }

	private:
		float audio_intensity;
		bool flashlight;

		MovementComponent* my_movement_component;
		CameraComponent* my_camera_component;
	};
}
#endif

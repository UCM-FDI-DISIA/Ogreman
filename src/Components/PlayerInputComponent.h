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
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		inline bool IsFlashLightPressed() { return flashlight; }

	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos;

		float audio_intensity;
		bool flashlight;

		MovementComponent* my_movement_component;
		CameraComponent* my_camera_component;
	};
}
#endif

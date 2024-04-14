#pragma once
#ifndef INPUTCOMPONENT
#define INPUTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"

namespace VeryReal {
	class TransformComponent;
	class CameraComponent;
}

namespace Ogreman {
	class MovementComponent;
	class PickUpComponent;
	class CellComponent;
	class NoteComponent;
}

namespace Ogreman {
	class OGREMAN_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		inline bool IsFlashLightPressed() { return flashlight; }
		void setCanPickUp(bool newValue);
		void setCellToGet(CellComponent* newCell);
		void setNoteToGet(NoteComponent* newNote);

		VeryReal::Vector3 getFacingDirection(const VeryReal::Vector3& rotation);

	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos;

		float audio_intensity;
		bool flashlight, canPickUp = false;

		VeryReal::TransformComponent* my_transform;
		Ogreman::MovementComponent* my_movement_component;
		VeryReal::CameraComponent* my_camera_component;
		Ogreman::PickUpComponent* my_pickup_component;
		Ogreman::CellComponent* cell_to_get = nullptr;
		Ogreman::NoteComponent* note_to_get = nullptr;
	};
}
#endif
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
	class RigidBodyComponent;
}

namespace Ogreman {
	class MovementComponent;
	class PickUpComponent;
	class CellComponent;
	class NoteComponent;
}

#pragma warning(disable : 4251)

namespace Ogreman {
	class OGREMAN_API PlayerInputComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		bool IsFlashLightPressed();
		void setCanPickUp(bool newValue);
		void setCellToGet(CellComponent* newCell);
		void setNoteToGet(NoteComponent* newNote);
		VeryReal::Entity* getCellToGet();
		VeryReal::Entity* getNoteToGet();
	private:
		double sensitivity = 0.1;
		std::pair<int32_t, int32_t> prev_mouse_pos = {-1, -1};

		float audio_intensity = 0;
		bool flashlight = false, canPickUp = false;

		VeryReal::TransformComponent* my_transform = nullptr;
		Ogreman::MovementComponent* my_movement_component = nullptr;
		VeryReal::CameraComponent* my_camera_component = nullptr;
		Ogreman::PickUpComponent* my_pickup_component = nullptr;
		Ogreman::CellComponent* cell_to_get = nullptr;
		Ogreman::NoteComponent* note_to_get = nullptr;
		VeryReal::RigidBodyComponent* my_rigidbody = nullptr;
	};
}

#pragma warning(default : 4251)

#endif
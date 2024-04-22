#pragma once
#ifndef PICKUPCOMPONENT
#define PICKUPCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include  "../Export.h"
namespace VeryReal {
	class TransformComponent;
	class CameraComponent;
	class Entity;
}

namespace Ogreman {
	class PlayerInteractionComponent;
	class PlayerInputComponent;
	class NoteComponent;
	class CellComponent;
}

namespace Ogreman {
	class OGREMAN_API PickUpComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
		void GetElement(NoteComponent* note, CellComponent* cell);

	private:
		VeryReal::TransformComponent* player_transform = nullptr;
		Ogreman::PlayerInteractionComponent* my_player_interaction_comp = nullptr;
		Ogreman::PlayerInputComponent* my_player_input_comp = nullptr;
		VeryReal::CameraComponent* my_player_cam = nullptr;
		bool control_update = false;
		float distance = 1000;
	};
}
#endif


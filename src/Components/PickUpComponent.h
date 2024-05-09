#pragma once
#ifndef PICKUPCOMPONENT
#define PICKUPCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include  "../Export.h"
namespace VeryReal {
	class TransformComponent;
	class Entity;
}

namespace Ogreman {
	class PlayerInteractionComponent;
	class PlayerInputComponent;
	class NoteComponent;
	class CellComponent;
	class NNotesComponent;
}

namespace Ogreman {
	class OGREMAN_API PickUpComponent : public VeryReal::Component {
	public:
		std::pair<bool, std::string> InitComponent();
		virtual void Update(const double& dt);
		void GetElement(NoteComponent* note, CellComponent* cell);

	private:
		void settam(VeryReal::Entity* obj);
		VeryReal::TransformComponent* player_transform = nullptr;
		Ogreman::PlayerInteractionComponent* my_player_interaction_comp = nullptr;
		Ogreman::PlayerInputComponent* my_player_input_comp = nullptr;
		Ogreman::NNotesComponent* my_notes = nullptr;
		bool control_update_cell = false;
		bool control_update_note = false;
		float distance = 1000;
	};
}
#endif


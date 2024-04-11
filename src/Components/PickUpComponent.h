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
}

namespace Ogreman {
	class OGREMAN_API PickUpComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
		void GetElement();

	private:
		VeryReal::TransformComponent* player_transform;
		Ogreman::PlayerInteractionComponent* my_player_interaction_comp;
		Ogreman::PlayerInputComponent* my_player_input_comp;
	};
}
#endif


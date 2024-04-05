#pragma once
#ifndef PICKUPCOMPONENT
#define PICKUPCOMPONENT
#include "Component.h"
#include "Vector3.h"

namespace VeryReal {
	class TransformComponent;
}

namespace Ogreman {
	class PlayerInteractionComponent;
}

namespace Ogreman {
	class PickUpComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
		void GetElement();

	private:
		VeryReal::TransformComponent* player_transform;
		Ogreman::PlayerInteractionComponent* my_player_interaction_comp;
	};
}
#endif


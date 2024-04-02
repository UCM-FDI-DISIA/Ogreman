#pragma once
#ifndef PICKUPCOMPONENT
#define PICKUPCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"

namespace VeryReal {
	class TransformComponent;
}

namespace VeryReal {
	class PickUpComponent : public Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

	private:
		TransformComponent* player_transform;
	};
}
#endif


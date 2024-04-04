#pragma once
#ifndef PICKUPCOMPONENT
#define PICKUPCOMPONENT
#include "Component.h"
#include "Vector3.h"

namespace VeryReal {
	class TransformComponent;
}

namespace Ogreman {
	class PickUpComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

	private:
		VeryReal::TransformComponent* player_transform;
	};
}
#endif


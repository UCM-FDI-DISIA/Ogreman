#pragma once
#ifndef MOVEMENTCOMPONENT
#define MOVEMENTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include "../Export.h"
namespace VeryReal {
	class TransformComponent;
	class Vector3;
}

namespace Ogreman {
	class OGREMAN_API MovementComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

		bool IsMoving();
		inline void SetMoventDirection(VeryReal::Vector3 newDirection) { movementDirection = newDirection; }
		inline void SetMoventDirectionX(float X) { movementDirection.SetX(X); }
		inline void SetMoventDirectionY(float Y) { movementDirection.SetY(Y); }
		inline void SetMoventDirectionZ(float Z) { movementDirection.SetZ(Z); }

	private:
		float speed = 15;
		VeryReal::Vector3 movementDirection = VeryReal::Vector3(1,0,0);

		VeryReal::TransformComponent* my_transform = nullptr;
	};
}
#endif



#pragma once
#ifndef MOVEMENTCOMPONENT
#define MOVEMENTCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"

namespace VeryReal {
	class TransformComponent;
}

namespace VeryReal {
	class MovementComponent : public Component {
	public:
		virtual void InitComponent();
		virtual void LateUpdate(const double& dt);

		inline bool IsMoving() { return movementDirection != Vector3(0, 0, 0); }
		inline void SetMoventDirection(Vector3 newDirection) { movementDirection = newDirection; }
		inline void SetMoventDirectionX(float X) { movementDirection.SetX(X); }
		inline void SetMoventDirectionY(float Y) { movementDirection.SetY(Y); }
		inline void SetMoventDirectionZ(float Z) { movementDirection.SetZ(Z); }

	private:
		TransformComponent* my_transform;

		float speed = 10;
		Vector3 movementDirection = Vector3(0,0,0);
	};
}
#endif

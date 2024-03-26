#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

bool VeryReal::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<TransformComponent>("TransformComponent");
	if (this->my_transform != nullptr)
		return true;
	else 
		return false;
}

void VeryReal::MovementComponent::LateUpdate(const double& dt) {
	if (IsMoving())
		my_transform->Translate(movementDirection * speed * dt);
}

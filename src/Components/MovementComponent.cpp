#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

bool Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>("TransformComponent");
	if (this->my_transform != NULL)
		return true;
	else 
		return false;
}

void Ogreman::MovementComponent::Update(const double& dt) {
	std::cout << my_transform->GetRotation().GetX() << " " << my_transform->GetRotation().GetY() << " " << my_transform->GetRotation().GetZ();

	if (IsMoving()) {
		my_transform->Translate(movementDirection * speed);
	}
}

bool Ogreman::MovementComponent::IsMoving()
{
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
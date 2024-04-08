#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

bool Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>("transform");
	if (this->my_transform != NULL)
		return true;
	else 
		return false;
}

void Ogreman::MovementComponent::Update(const double& dt) 
{
	std::cout << my_transform->GetPosition().GetX() << " " << my_transform->GetPosition().GetY() << " " << my_transform->GetPosition().GetZ();

	if (IsMoving()) {
		my_transform->Translate(movementDirection * speed);
	}
	else {
		std::cout << "NO" << std::endl;
		my_transform->Translate(movementDirection);
	}
}

bool Ogreman::MovementComponent::IsMoving()
{
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
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

	if (IsMoving()) {
		
		std::cout << movementDirection.GetX();
		std::cout << movementDirection.GetY();
		std::cout << movementDirection.GetZ();
		my_transform->Translate(movementDirection * speed);

	}
}

bool Ogreman::MovementComponent::IsMoving()
{
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
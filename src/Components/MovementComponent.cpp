#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"

bool Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>("TransformComponent");
	if (this->my_transform != nullptr)
		return true;
	else 
		return false;
}

void Ogreman::MovementComponent::Update(const double& dt) {
	if (IsMoving()) {
		my_transform->Translate(movementDirection * speed * dt);
		//std::cout << "Hola" << std::endl;
	}
}

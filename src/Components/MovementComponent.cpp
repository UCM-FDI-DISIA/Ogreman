#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "Vector3.h"

using namespace std;

bool Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (this->my_transform != nullptr)
		return true;
	else 
		return false;
}

void Ogreman::MovementComponent::Update(const double& dt) {
	if (IsMoving()) {
        my_transform->Translate(movementDirection * (float)(speed * dt ));
	}
}

bool Ogreman::MovementComponent::IsMoving() {
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
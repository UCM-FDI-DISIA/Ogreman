//#include "MovementComponent.h"
//#include <TransformComponent.h>
//#include <Entity.h>
//
//void VeryReal::MovementComponent::InitComponent(){
//
//	my_transform = this->GetEntity()->GetComponent<TransformComponent>("TransformComponent");
//}
//
//void VeryReal::MovementComponent::LateUpdate(const double& dt) {
//	if (IsMoving())
//		my_transform->Translate(movementDirection * speed * dt);
//}
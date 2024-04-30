#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
using namespace std;

bool Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (this->my_transform != nullptr && this->my_rigidbody != nullptr)
		return true;
	else 
		return false;
}

void Ogreman::MovementComponent::Update(const double& dt) {

	std::cout << my_rigidbody->GetVelocity().Magnitude()<<std::endl;
	if (IsMoving()) {
       my_rigidbody->SetVelocityLinear(movementDirection * (float)(speed/**dt*/));
		//my_rigidbody->SetVelocityLinear(VeryReal::Vector3(1000,0,0));
	}
	/*else if(my_rigidbody->GetVelocity().Magnitude())*/
	else
	{
		my_rigidbody->Decelerate(4);
	}
}

bool Ogreman::MovementComponent::IsMoving() {
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
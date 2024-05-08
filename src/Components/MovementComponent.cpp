#include "MovementComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
using namespace std;

std::pair<bool, std::string> Ogreman::MovementComponent::InitComponent(){
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (this->my_transform == nullptr)
		return { false,"The entity doesn't have Transform Componet, Error from MovementComponent" };
	 if (this->my_rigidbody == nullptr)
		return { false,"The entity doesn't have RigidBody Componet, Error from MovementComponent" };
	else
		return { true, "The MovementComponent was made correctly" };
}

void Ogreman::MovementComponent::Update(const double& dt) 
{
	std::cout << my_transform->GetPosition().GetX() << "  " << my_transform->GetPosition().GetY() << " " << my_transform->GetPosition().GetZ() << "\n";
	if (IsMoving() && IsGrounded()) {
       my_rigidbody->SetVelocityLinear(movementDirection * (float)(speed*dt));
	}
}

bool Ogreman::MovementComponent::IsMoving() {
	return movementDirection != VeryReal::Vector3(0, 0, 0);
}
bool Ogreman::MovementComponent::IsGrounded() {
	return abs(my_rigidbody->GetVelocity().GetY()) < 0.01;
}
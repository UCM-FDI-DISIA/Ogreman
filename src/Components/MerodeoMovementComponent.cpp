#include "MerodeoMovementComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <cstdlib>

using namespace Ogreman;
MerodeoMovementComponent::MerodeoMovementComponent() {
	transfrormcomponent = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	rigidbodycomponent = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
}
MerodeoMovementComponent::~MerodeoMovementComponent() {

}
int MerodeoMovementComponent::random360() {
	int random = rand() % 361;
	int signo = rand() % 2;
	if (signo == 0) {
		return random;
	}
	else return -random;
}
void MerodeoMovementComponent::Update(const double& dt){
	if (timertochange < actualtimer) {
		//si mi tiempo actual es mayor que cuando deberia cambiar entonces actualizo direcciones
		
		
		Vector3 fDirection = transfrormcomponent->GetPosition();
		Vector3 bdirection = Vector3(-fDirection.GetX(), -fDirection.GetY(), -fDirection.GetZ());
		Vector3 wanderDirection = bdirection.Normalize()* 3;

		Vector3 targetcosa = transfrormcomponent->GetPosition() + wanderDirection;
		Vector3 randomvec = Vector3(random360(), 0, random360());
		targetcosa += randomvec * wanderRange;
		
		Vector3 targetOrientation = targetcosa + transfrormcomponent->GetRotation();
		targetcosa = transfrormcomponent->GetPosition() + transfrormcomponent->GetRotation();
		targetcosa += targetOrientation;
			
		Vector3 lineal = Vector3(targetcosa.GetX() * aceleration, 0, targetcosa.GetZ() * aceleration);

		rigidbodycomponent->SetVelocityLinear(lineal);
	}
	else actualtimer += dt;
	
}
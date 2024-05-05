#include "MerodeoMovementComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <cstdlib>

using namespace Ogreman;
MerodeoMovementComponent::MerodeoMovementComponent() {
	
}
MerodeoMovementComponent::~MerodeoMovementComponent() {

}
bool MerodeoMovementComponent::InitComponent() {
	transfrormcomponent = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	rigidbodycomponent = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	aceleration = 1;
	timertochange = 3;
	return true;
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
	std::cout << "PEPA" << std::endl;
	if (timertochange < actualtimer) {
		//si mi tiempo actual es mayor que cuando deberia cambiar entonces actualizo direcciones
		
		
		Vector3 pos = transfrormcomponent->GetPosition();
		Vector3 dir = Vector3(-pos.GetX(), -pos.GetY(), -pos.GetZ());
		Vector3 wanderDirection = dir.Normalize()* 3;

		Vector3 targetcosa = pos + wanderDirection;
		Vector3 randomvec = Vector3((float)random360(), 0, (float)random360());
		targetcosa += randomvec;
		
		/*Vector3 targetOrientation = targetcosa + transfrormcomponent->GetRotation();
		targetcosa = transfrormcomponent->GetPosition() + transfrormcomponent->GetRotation();
		targetcosa += targetOrientation;*/
			
		Vector3 lineal = Vector3(targetcosa.GetX() * aceleration, 0, targetcosa.GetZ() * aceleration);

		rigidbodycomponent->SetVelocityLinear(lineal);
		actualtimer = 0;
		
	}
	else actualtimer += dt;
	
}
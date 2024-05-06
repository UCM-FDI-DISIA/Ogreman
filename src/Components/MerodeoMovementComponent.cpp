#include "MerodeoMovementComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <cstdlib>

using namespace Ogreman;
using namespace VeryReal;
MerodeoMovementComponent::MerodeoMovementComponent() {
	
}
MerodeoMovementComponent::~MerodeoMovementComponent() {

}
bool MerodeoMovementComponent::InitComponent() {
	transfrormcomponent = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (transfrormcomponent == nullptr) {
	#ifdef _DEBUG
		std::cout << "No se puede añadir el component MerodeoComponent dado que la entidad no tiene TransformComponent\n";
	#endif // DEBUG
		return false;
	}
	rigidbodycomponent = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (rigidbodycomponent == nullptr) {
	#ifdef _DEBUG
			std::cout << "No se puede añadir el component MerodeoComponent dado que la entidad no tiene RigidBody\n";
	#endif // DEBUG
		return false;
	}
	aceleration = 1;
	timertochange = 3;
	rigidbodycomponent->Rotate(Vector3(1, 0, 0), 180);
	return true;
}
float MerodeoMovementComponent::random360() {
	/*int random = rand() % 360;
	int signo = rand() % 2;
	int vel = rand() % 3;
	switch (vel)
	{
	case 0:
		velocityx *= -1;
		velocityz *= -1;
		break;
	case 1:

		velocityz *= -1;
		break;

	case 2:
		velocityx *= -1;
		break;

	default:
		break;
	}*/
	float vel = rand() % 5;
	int signo = rand() % 2;
	if (signo == 0) {

		return vel;
	}
	else {
		
		return -vel;
	}
	return vel;
	
	return 0;
	
}

float MerodeoMovementComponent::RotationY(Vector3& vector1, Vector3& vector2) {
	// Calcular el ángulo entre los dos vectores usando el producto punto
	float dotProduct = vector1.Dot(vector2);
	float magnitude1 = vector1.Magnitude();
	float magnitude2 = vector2.Magnitude();
	float angle = std::acos(dotProduct / (magnitude1 * magnitude2));

	// Calcular el vector de rotación usando el producto cruz
	VeryReal::Vector3 rotationAxis = vector1.Cross(vector2).Normalize();

	// Extraer la componente y del vector de rotación
	float rotation_y = rotationAxis.GetY(); // Suponiendo que GetY() devuelve la componente y

	// Determinar la dirección de rotación
	int dir = (rotation_y > 0) ? -1 : 1;

	angle = (angle * 180 / 3.1415) * dir;
	return angle;
}

void MerodeoMovementComponent::Update(const double& dt){
	if (timertochange < actualtimer) {
		//si mi tiempo actual es mayor que cuando deberia cambiar entonces actualizo direccione
		/*
		Vector3 pos = transfrormcomponent->GetPosition();
		Vector3 dir = Vector3(-pos.GetX(), -pos.GetY(), -pos.GetZ());
		Vector3 wanderDirection = dir.Normalize()* 3;

		Vector3 targetcosa = pos + wanderDirection;
		Vector3 randomvec = Vector3((float)random360(), 0, (float)random360());
		targetcosa += randomvec;
		*/
		/*Vector3 targetOrientation = targetcosa + transfrormcomponent->GetRotation();
		targetcosa = transfrormcomponent->GetPosition() + transfrormcomponent->GetRotation();
		targetcosa += targetOrientation;*/
			
		//Vector3 lineal = Vector3(targetcosa.GetX() * aceleration, 0, targetcosa.GetZ() * aceleration);

		//rigidbodycomponent->SetVelocityLinear(lineal);


		/*Vector3 pos = transfrormcomponent->GetPosition();
		Vector3 direction = transfrormcomponent->getFacingDirection();
		direction = direction.Normalize();*/
		
		//rigidbodycomponent->Rotate(Vector3(0, 1, 0), random360());
		

		/*nextvel = Vector3(random360(), 0, random360());
		
		rigidbodycomponent->Rotate(Vector3(0, 1, 0), RotationY(actual, nextvel));*/
		//std::cout << sig.GetX()<<" "<<sig.GetZ()<<" " << std::endl;

		Vector3 actual = transfrormcomponent->getFacingDirection();
		nextvel = Vector3 (random360(), 0, random360());
		rigidbodycomponent->Rotate(Vector3(0, 1, 0), RotationY(actual, nextvel));
		actualtimer = 0;
	}
	else actualtimer += dt;
	rigidbodycomponent->SetVelocityLinear(nextvel);
}
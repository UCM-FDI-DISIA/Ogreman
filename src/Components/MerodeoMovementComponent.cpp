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
std::pair<bool, std::string> MerodeoMovementComponent::InitComponent() {
	transfrormcomponent = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (transfrormcomponent == nullptr) {
		return { false, "The entity doesn't have TransformComponent" };
	}
	rigidbodycomponent = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (rigidbodycomponent == nullptr) {
		return { false, "The entity doesn't have RigidBodyComponent" };
	}
	aceleration = 1;
	timertochange = 3;
	rigidbodycomponent->Rotate(Vector3(1, 0, 0), 180);
	return { true,"The MerodeoComponent was made it correct" };
}
float MerodeoMovementComponent::random360() {
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
		Vector3 actual = transfrormcomponent->getFacingDirection();
		nextvel = Vector3 (random360(), 0, random360());
		rigidbodycomponent->Rotate(Vector3(0, 1, 0), RotationY(actual, nextvel));
		actualtimer = 0;
	}
	else actualtimer += dt;
	rigidbodycomponent->SetVelocityLinear(nextvel);
}
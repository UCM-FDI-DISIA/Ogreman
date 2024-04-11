#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
#include "InputManager.h"
Ogreman::OgremanControllerComponent::OgremanControllerComponent():trans(nullptr),animation(nullptr),current_index(0),current_states(patrol),current_node(nullptr), collider(nullptr){

}
Ogreman::OgremanControllerComponent::~OgremanControllerComponent() {

}
bool Ogreman::OgremanControllerComponent::InitComponent() {

	trans = GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (trans == nullptr) {
		#ifdef DEBUG
		std : .cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene TransformComponent\n";
		#endif // DEBUG

		return false;
	}
	animation= GetEntity()->GetComponent<VeryReal::AnimatorComponent>();
	if (animation == nullptr) {
		#ifdef DEBUG
				std : .cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene AnimatorComponent\n";
		#endif // DEBUG
				return false;
	}
	animation->setAnimation("Dance",true,true);
	all_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	patrol_nodes = Ogreman::GameManager::Instance()->GetPatrolNode();
	if (patrol_nodes.size() < 1) {
	#ifdef DEBUG
			std : .cout << "No hay nodos de patrulla regitrados\n";
	#endif // DEBUG
		return false;
	}
	current_node = patrol_nodes[current_index];
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (current_node_trans == nullptr) {
	#ifdef DEBUG
			std : .cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene TransformComponent "<<patrol_nodes[current_index]->GetID()<<"\n";
	#endif // DEBUG

		return false;
	}
	collider= GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (collider == nullptr) {
		if (current_node_trans == nullptr) {
#ifdef DEBUG
			std : .cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene ColliderComponent " << patrol_nodes[current_index]->GetID() << "\n";
#endif // DEBUG

			return false;
		}
	}
	current_states = patrol;
	std::cout <<"PATROL_NODES " << patrol_nodes.size() << "\n";

	return true;
}
// Calcular el vector de rotación entre dos vectores
VeryReal::Vector3 Ogreman::OgremanControllerComponent::calculateRotationVector( VeryReal::Vector3& sourceVector,  VeryReal::Vector3& targetVector) {
	VeryReal::Vector3 rotationAxis = sourceVector.Cross(targetVector);

	// Calcula el ángulo de rotación utilizando el producto punto
	float dotProduct = sourceVector.Dot(targetVector);
	float sourceMagnitude = sourceVector.Magnitude();
	float targetMagnitude = targetVector.Magnitude();
	float cosTheta = dotProduct / (sourceMagnitude * targetMagnitude);

	// Asegúrate de que cosTheta esté en el rango [-1, 1]
	cosTheta = std::max(-1.0f, std::min(1.0f, cosTheta));

	// Calcula el ángulo de rotación en radianes
	float rotationAngleRadians = std::acos(cosTheta);

	// Convierte el ángulo a grados
	float rotationAngleDegrees = rotationAngleRadians * (180.0f / 3.1415);

	// Normaliza el vector de rotación
	if (rotationAngleRadians != 0) {
		rotationAxis.Normalize();
	}

	// Devuelve el vector de rotación multiplicado por el ángulo en grados
	return rotationAxis * rotationAngleDegrees;
}

void Ogreman::OgremanControllerComponent::Update(const double& dt) {
	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();
	VeryReal::Entity* col_ent=nullptr;
	VeryReal::Vector3 vec(0,0,0), rot(0,0,0);
	float yaw=0, pitch=0,diff;
	switch (current_states)
	{


	case Ogreman::OgremanControllerComponent::stop:
		break;
	case Ogreman::OgremanControllerComponent::patrol:
		dif = dif.Normalize();
		dif *= 0.01;
		trans->SetPosition(trans->GetPosition() + dif);
		
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_Q)) {
			current_index = (current_index + 1) % patrol_nodes.size();
			current_node = patrol_nodes[current_index];
			current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();

			
		
			if (yaw > 0.2) {
				rot.SetY(yaw);
				trans->Rotate(trans->GetRotation() + rot);
				VeryReal::Vector3 sunma = trans->GetRotation() + rot;
				std::cout << sunma.GetX() << " " << sunma.GetY() << sunma.GetZ() << "\n";
			}




		}
		


		break;
	case Ogreman::OgremanControllerComponent::pathfinding:
		break;
	case Ogreman::OgremanControllerComponent::follow:
		break;
	default:
		break;
	}

 }
void Ogreman::OgremanControllerComponent::OnCollisionEnter(VeryReal::Entity* other) {
	if (other != nullptr && other->GetComponent<NodeComponent>() != nullptr) {
		std::cout << "\nHAY COLISION\N";
		current_index = (current_index + 1) % patrol_nodes.size();
		current_node = patrol_nodes[current_index];
		current_node_trans= current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();

	}


 }
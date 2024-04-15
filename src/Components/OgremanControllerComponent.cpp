#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
#include "InputManager.h"
#include <cmath> 
#include <math.h>
#define DEBUG
Ogreman::OgremanControllerComponent::OgremanControllerComponent():trans(nullptr),animation(nullptr),current_index(0),current_states(pathfinding),current_node(nullptr), collider(nullptr){

}
Ogreman::OgremanControllerComponent::~OgremanControllerComponent() {

}
bool Ogreman::OgremanControllerComponent::InitComponent() {

	trans = GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (trans == nullptr) {
		#ifdef DEBUG
		std ::cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene TransformComponent\n";
		#endif // DEBUG

		return false;
	}
	animation= GetEntity()->GetComponent<VeryReal::AnimatorComponent>();
	if (animation == nullptr) {
		#ifdef DEBUG
				std::cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene AnimatorComponent\n";
		#endif // DEBUG
				return false;
	}
	animation->setAnimation("Dance",true,true);
	all_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	patrol_nodes = Ogreman::GameManager::Instance()->GetPatrolNode();
	
	if (patrol_nodes.size() < 1) {
	#ifdef DEBUG
			std ::cout << "No hay nodos de patrulla regitrados\n";
	#endif // DEBUG
		return false;
	}
	current_node = patrol_nodes[current_index];
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (current_node_trans == nullptr) {
	#ifdef DEBUG
			std::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene TransformComponent "<<patrol_nodes[current_index]->GetID()<<"\n";
	#endif // DEBUG

		return false;
	}
	collider= GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (collider == nullptr) {
		if (current_node_trans == nullptr) {
#ifdef DEBUG
			std ::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene ColliderComponent " << patrol_nodes[current_index]->GetID() << "\n";
#endif // DEBUG

			return false;
		}
	}
	current_states = patrol;
	std::cout <<"PATROL_NODES " << patrol_nodes.size() << "\n";


	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();
	VeryReal::Vector3 myforward = trans->getFacingDirection();
	VeryReal::Vector3 vec(0, 0, 0), rot(0, 0, 0);
	vec = current_node_trans->GetPosition();
	rot = CalculateRotationVector(myforward, vec);
	std::cout << "Rotación: " << trans->GetRotation().GetY() << std::endl;
	trans->SetRotation(trans->GetRotation() +rot);
	

	//std::cout << "Rotación resultante: " << trans.GetY() << std::endl;
	grid = GameManager::Instance()->GetGris();
	return true;
}
// Calcular el vector de rotación entre dos vectores
VeryReal::Vector3 Ogreman::OgremanControllerComponent::CalculateRotationVector(VeryReal::Vector3& from, VeryReal::Vector3& toPosition) {
	// Normaliza el vector de dirección
	VeryReal::Vector3 direction = (toPosition - from).Normalize();

	// Calcula el ángulo de rotación en el eje Y
	float rotationAngleRadians = std::atan2(direction.GetX(), direction.GetZ());

	// Convierte el ángulo de rotación a grados
	int rotationAngleDegrees = static_cast<int>(rotationAngleRadians * (180.0f / 3.1415));

	// Crea un vector de rotación en el eje Y
	VeryReal::Vector3 rotationVector(0, rotationAngleDegrees, 0);

	return rotationVector;
}
void Ogreman::OgremanControllerComponent::Update(const double& dt) {
	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();

	VeryReal::Vector3 dif_player;
	if(player_trns!=nullptr) dif_player = player_trns->GetPosition() - trans->GetPosition();
	VeryReal::Vector3 myforward = trans->getFacingDirection();
	VeryReal::Entity* col_ent=nullptr;
	VeryReal::Vector3 vec(0,0,0), rot(0,0,0);
	vec = current_node_trans->GetPosition();
	float yaw=0, pitch=0,diff;
	switch (current_states)
	{


	case Ogreman::OgremanControllerComponent::stop:
		break;
	case Ogreman::OgremanControllerComponent::patrol:
		dif = dif.Normalize();
		dif *= 0.01f;
		trans->SetPosition(trans->GetPosition() + dif);
		
		
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_Q)) {
			current_index = (current_index + 1) % patrol_nodes.size();
			current_node = patrol_nodes[current_index];
			current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
			if (once) {
				vec = current_node_trans->GetPosition();
				rot = CalculateRotationVector(myforward, vec);

				trans->SetRotation(trans->GetRotation() + rot);

				std::cout << "Rotación: " << trans->GetRotation().GetY() << std::endl;

				std::cout << "Rotación resultante: " << rot.GetY() << std::endl;
				once = false;
			}
			
			
			




		}
		


		break;
	case Ogreman::OgremanControllerComponent::pathfinding:

		if (Astar_nodes.size() <= 0) {
			Astar_nodes = grid->getPathAStar(trans->GetPosition(), VeryReal::Vector3(10, 0, 10));


		}


		break;
	case Ogreman::OgremanControllerComponent::follow:
		dif_player = dif_player.Normalize();
		dif_player *= 0.01f;
		trans->SetPosition(trans->GetPosition() + dif_player);


		break;
	default:
		break;
	}

 }
void Ogreman::OgremanControllerComponent::setPlayerTransform(VeryReal::TransformComponent* t) {
	player_trns = t;


}
void Ogreman::OgremanControllerComponent::SetState(int state) {
	current_states = (states)state;
}
int  Ogreman::OgremanControllerComponent::GetState() {
	return int(current_states);
}
void Ogreman::OgremanControllerComponent::OnCollisionEnter(VeryReal::Entity* other) {
	if (other != nullptr && other->GetComponent<NodeComponent>() != nullptr && other->GetComponent<NodeComponent>()->GetID()!=current_node->GetID()) {
		std::cout << "\nHAY COLISION\n";
		current_index = (current_index + 1) % patrol_nodes.size();
		current_node = patrol_nodes[current_index];
		current_node_trans= current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();

	}


 }
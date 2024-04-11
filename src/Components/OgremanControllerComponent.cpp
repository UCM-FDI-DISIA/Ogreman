#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
Ogreman::OgremanControllerComponent::OgremanControllerComponent():trans(nullptr),animation(nullptr),current_index(0),current_states(patrol),current_node(nullptr) {

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
	}
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
	current_states = patrol;


	return true;
}
void Ogreman::OgremanControllerComponent::Update(const double& dt) {
	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();
	
	switch (current_states)
	{


	case Ogreman::OgremanControllerComponent::stop:
		break;
	case Ogreman::OgremanControllerComponent::patrol:
		dif = dif.Normalize();
		dif *= 0.01;
		trans->SetPosition(trans->GetPosition() + dif);

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
		current_index = (current_index + 1) % patrol_nodes.size();
		current_node = patrol_nodes[current_index];
		current_node_trans= current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();

	}


 }
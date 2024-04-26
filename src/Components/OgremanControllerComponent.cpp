#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
#include "InputManager.h"
#include <cmath> 
#include <math.h>

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
	dif.SetY(0);
	VeryReal::Vector3 myforward = trans->getFacingDirection();
	VeryReal::Vector3 vec(0, 0, 0), rot(0, 0, 0);
	vec = current_node_trans->GetPosition();
	float rota = CalculateRotationVector(myforward, dif);
	std::cout << "Rotación:  YYYY" << rota * 180 / 3.14f << std::endl;
	vec.SetX(trans->GetRotation().GetX());
	vec.SetY(trans->GetRotation().GetY() - rota * 180 / 3.14f);
	vec.SetZ(trans->GetRotation().GetZ());
	trans->SetRotation(vec);
	std::cout << trans->getFacingDirection().Dot(dif) << " " << rota << "\n";
	if (trans->getFacingDirection().Dot(dif)!=0) {
		std::cout << trans->getFacingDirection().Dot(dif) << " " << rota << "\n";
		std::cout << "ENRA\n";
		vec.SetY(trans->GetRotation().GetY() + 2 );
		trans->SetRotation(vec);
	}

	//std::cout << "Rotación resultante: " << trans.GetY() << std::endl;
	grid = GameManager::Instance()->GetGris();
	return true;
}
// Calcular el vector de rotación entre dos vectores
float Ogreman::OgremanControllerComponent::CalculateRotationVector(VeryReal::Vector3& miro, VeryReal::Vector3& voy) {
	float d = (miro.Dot(voy) / (miro.Magnitude() * voy.Magnitude()));
	float numero=std::acos(d);
	return numero;
}

void Ogreman::OgremanControllerComponent::Update(const double& dt) {
	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();

	VeryReal::Vector3 dif_player;
	if(player_trns!=nullptr) dif_player = player_trns->GetPosition() - trans->GetPosition();
	VeryReal::Vector3 myforward = trans->getFacingDirection();
	VeryReal::Entity* col_ent=nullptr;
	VeryReal::Vector3 vec(0,0,0), rot(0,0,0);
	vec = current_node_trans->GetPosition();
	float yaw=0, pitch=0,diff = 0,rota;
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
				rota = CalculateRotationVector(myforward, dif);
				std::cout << "Rotación:  YYYY" << rota * 180 / 3.14 << std::endl;
				vec.SetX(trans->GetRotation().GetX());
				vec.SetY(trans->GetRotation().GetY() - rota * 180.0f / 3.14f);
				vec.SetZ(trans->GetRotation().GetZ());
				trans->SetRotation(vec);

				std::cout << trans->getFacingDirection().Dot(dif) << " " << trans->getFacingDirection().Normalize().GetY() - dif.Normalize().GetY() << "\n";
				while (trans->getFacingDirection().Dot(dif) != 0) {
					std::cout << "ENRA\n";
					vec.SetY(trans->GetRotation().GetY() + 2 );
					trans->SetRotation(vec);
				}
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
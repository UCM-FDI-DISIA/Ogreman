#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
#include "InputManager.h"
#include <cmath> 
#include <math.h>
#include "SceneManager.h"
#include "Scene.h"

#include "TransformComponent.h"
#include "AnimatorComponent.h"

#include "ColliderComponent.h"
#include "Vector3.h"
#include "RigidBodyComponent.h"
Ogreman::OgremanControllerComponent::OgremanControllerComponent():last_node(false),rotation_y(0),trans(nullptr),animation(nullptr),current_index(0),current_states(pathfinding),current_node(nullptr), collider(nullptr){

}

Ogreman::OgremanControllerComponent::~OgremanControllerComponent() {

}
float RotationYBetween(VeryReal::Vector3& vector1, VeryReal::Vector3& vector2) {
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

std::pair<bool, std::string> Ogreman::OgremanControllerComponent::InitComponent(float alignmentWeight, float cohesionWeight, float separationWeight, float maxSpeed, float separationDistance, float min_dist_follow, float max_dist_follow) {
	this->alignmentWeight = alignmentWeight;
	this->cohesionWeight = cohesionWeight;
	this->separationWeight = separationWeight;
	this->maxSpeed = maxSpeed;
	this->separationDistance = separationDistance;
	this->min_dist_follow = min_dist_follow;
	this->max_dist_follow = max_dist_follow;
	trans = GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (trans == nullptr) {

		return { false, "Transform Component isn't in this entity, ERROR from OgremanControllerComponent" };
	}
	animation= GetEntity()->GetComponent<VeryReal::AnimatorComponent>();
	if (animation == nullptr) {
		return { false, "AnimatorComponent isn't in this entity, ERROR from OgremanControllerComponent" };
	}
	animation->setAnimation("RunTop",true,true);
	animation->setAnimation("RunBase", true, true);
	my_rb= GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (my_rb == nullptr) {
		return { false, "RigidBodyComponent isn't in this entity, ERROR from OgremanControllerComponent" };
	}

	all_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	patrol_nodes = Ogreman::GameManager::Instance()->GetPatrolNode();
	
	if (patrol_nodes.size() < 1) {
		return { false, "There isn't NodoPatrullas" };
	}
	current_node = patrol_nodes[current_index];
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (current_node_trans == nullptr) {
	#ifdef _DEBUG
			std::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene TransformComponent "<<patrol_nodes[current_index]->GetID()<<"\n";
	#endif // DEBUG

			return { false, "" };
	}
	collider= GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (collider == nullptr) {
		if (current_node_trans == nullptr) {
#ifdef _DEBUG
			std ::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene ColliderComponent " << patrol_nodes[current_index]->GetID() << "\n";
#endif // DEBUG

			return { false, "" };
		}
	}
	current_states = patrol;
	//std::cout <<"PATROL_NODES " << patrol_nodes.size() << "\n";
	

	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();
	
	VeryReal::Vector3 vector_facing = trans->getFacingDirection();
	//my_rb->Rotate(VeryReal::Vector3(0, 1, 0),RotationYBetween(vector_facing,dif));
	my_rb->Rotate(VeryReal::Vector3(1,0, 0), 180);

	grid = GameManager::Instance()->GetGris();
	VeryReal::Vector3 v(10, 0, -30);
	player_trns = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	
	GoToLocation(v);
	return { true, "" };
}
// Función para alinear al ogro con el grupo
VeryReal::Vector3 Ogreman::OgremanControllerComponent::align() {
	// En este caso, el ogro simplemente mira hacia la posición del jugador
	//return trans_player->get - trans.position;
	return trans->getFacingDirection();
}

// Función para mantener al grupo cohesionado
VeryReal::Vector3 Ogreman::OgremanControllerComponent::cohere() {
	// En este caso, el ogro se dirige hacia la posición del jugador
	return player_trns->GetPosition() - trans->GetPosition();
}

// Función para evitar que los ogros choquen entre sí
VeryReal::Vector3 Ogreman::OgremanControllerComponent::separate() {
	// En este caso, el ogro intenta mantener una distancia mínima del jugador
	// Distancia mínima entre el ogro y el jugador
	VeryReal::Vector3 direction = player_trns->GetPosition() - trans->GetPosition();
	float distance = direction.Magnitude();
	if (distance < separationDistance) {

		VeryReal::Vector3 v;
		v = direction.Normalize();
		v *= -1;
		return v; // Si está demasiado cerca, se aleja
	}
	else {
		return { 0, 0, 0 }; // Si está a una distancia segura, no hace nada
	}
}

void Ogreman::OgremanControllerComponent::GoToLocation(VeryReal::Vector3& to) {

	current_states = pathfinding;
	Astar_nodes = grid->GetPathDikstra(trans->GetPosition(),to);
	if (Astar_nodes.size() <= 0) { std::cout << "no hay nodos en el a estrella\n"; return; }
	NextNodePF();
}


void Ogreman::OgremanControllerComponent::Update(const double& dt) {
	 dif = current_node_trans->GetPosition() - trans->GetPosition();

	VeryReal::Vector3 dif_player;
	if(player_trns!=nullptr) dif_player = player_trns->GetPosition() - trans->GetPosition();
	VeryReal::Vector3 myforward = trans->getFacingDirection();
	float dist_player = sqrt(player_trns->GetPosition().GetX() * player_trns->GetPosition().GetX() + player_trns->GetPosition().GetY() * player_trns->GetPosition().GetY() + player_trns->GetPosition().GetZ() * player_trns->GetPosition().GetZ());
	VeryReal::Vector3 vec(0,0,0), rot(0,0,0); 
	vec = current_node_trans->GetPosition();
	// Calcular vectores de dirección para los comportamientos de Flocking
	VeryReal::Vector3 alignment, cohesion, separation, totalDirection;
	float yaw=0, pitch=0,diff = 0,rota=0,dist=0;

	if (dist_player < min_dist_follow && current_states != follow)current_states = follow;
	else if (dist_player > max_dist_follow && current_states == follow)RestartPatrol();
	//std::cout << dist_player << "\n";
	switch (current_states) {


	case Ogreman::OgremanControllerComponent::stop:
		break;
	case Ogreman::OgremanControllerComponent::patrol:
		dif = dif.Normalize();
		dif *= maxSpeed;
		my_rb->SetVelocityLinear(dif);
		my_rb->Rotate(VeryReal::Vector3(0, 1, 0), RotationYBetween(myforward, dif));
		//std::cout << dif.GetX() << " \n";
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_T)) {
			NextNodePT();
		}

		break;
	case Ogreman::OgremanControllerComponent::pathfinding:

		
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_T) ) {
			if (last_node)RestartPatrol();
			else NextNodePF();

		}
			dif = dif.Normalize();
			dif *= maxSpeed;
			my_rb->SetVelocityLinear(dif);
			my_rb->Rotate(VeryReal::Vector3(0, 1, 0), RotationYBetween(myforward, dif));
		break;
	case Ogreman::OgremanControllerComponent::follow:
		 alignment = align();
		 cohesion = cohere();
		 separation = separate();
		 totalDirection = alignment * alignmentWeight + cohesion * cohesionWeight + separation * separationWeight;

		 // Limitar la velocidad máxima
		 if (totalDirection.Magnitude() > maxSpeed) {
			 totalDirection = totalDirection.Normalize() * maxSpeed;
		 }

		 my_rb->Rotate(VeryReal::Vector3(0, 1, 0), RotationYBetween(myforward, totalDirection));
		 // Establecer la velocidad lineal del ogro hacia la posición del jugador
		 my_rb->SetVelocityLinear(totalDirection);
	


		break;
	default:
		break;
	}

 }
 void Ogreman::OgremanControllerComponent::RestartPatrol() {
	 if (current_states != patrol) {
		 if (current_node->GetPatrol()) {
			 current_states = patrol;
			 current_index = current_node->GetID();
			 NextNodePT();

			 last_node = false;
		 }
		 else {
			 current_states = pathfinding;
			 last_node = false;
			 Astar_nodes = grid->GetPathDikstra(trans->GetPosition(), patrol_nodes[0]->GetEntity()->GetComponent<VeryReal::TransformComponent>()->GetPosition());
			 
			 if (current_node->GetID() == Astar_nodes.front()->GetID()) {
				 Astar_nodes.pop_front();
				 if (Astar_nodes.size() > 0)NextNodePF();
			 }

		 }
		



	 }

 }
void Ogreman::OgremanControllerComponent::setPlayerTransform(VeryReal::TransformComponent* t) {
	player_trns = t;
}

void Ogreman::OgremanControllerComponent::SetState(int state) {
	current_states = (states)state;
}
void Ogreman::OgremanControllerComponent::NextNodePT() {
	current_index = (current_index + 1) % patrol_nodes.size();
	current_node = patrol_nodes[current_index];
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	/*VeryReal::Vector3 facing = trans->getFacingDirection();
	dif = trans->GetPosition() - current_node_trans->GetPosition();
	my_rb->Rotate(VeryReal::Vector3(0, 1, 0), RotationYBetween(facing, dif));*/
	
}
int  Ogreman::OgremanControllerComponent::GetState() {
	return int(current_states);
}
void Ogreman::OgremanControllerComponent::NextNodePF() {
	current_node = Astar_nodes.front();
	Astar_nodes.pop_front();
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	VeryReal::Vector3 facing = trans->getFacingDirection();
	/*dif= trans->GetPosition() - current_node_trans->GetPosition();
	my_rb->Rotate(VeryReal::Vector3(0, 1, 0),RotationYBetween(facing, dif));*/

	facing = trans->getFacingDirection();
	if (Astar_nodes.size() == 0)last_node = true;
}
void Ogreman::OgremanControllerComponent::OnCollisionEnter(VeryReal::Entity* other) {
	
	if (current_states==patrol && other != nullptr && other->HasComponent("NodeComponent") && other->GetComponent<NodeComponent>()->GetID()==  current_node->GetID()) {
		std::cout << "\nHAY COLISION\n";
		NextNodePT();

	}
	else if (current_states == pathfinding && other!=nullptr &&other->HasComponent("NodeComponent")) {
		if (last_node)RestartPatrol();
		else NextNodePF();


	}
 }
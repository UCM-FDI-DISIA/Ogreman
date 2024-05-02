#include "OgremanControllerComponent.h"
#include "GameManager.h"
#include "Entity.h"
#include "InputManager.h"
#include <cmath> 
#include <math.h>

Ogreman::OgremanControllerComponent::OgremanControllerComponent():last_node(false),rotation_y(0),trans(nullptr),animation(nullptr),current_index(0),current_states(pathfinding),current_node(nullptr), collider(nullptr){

}

Ogreman::OgremanControllerComponent::~OgremanControllerComponent() {

}
float RotationYBetween( VeryReal::Vector3& vector1,  VeryReal::Vector3& vector2) {
	// Calcular el ángulo entre los dos vectores usando el producto punto
	float dotProduct = vector1.Dot(vector2);
	float magnitude1 = vector1.Magnitude();
	float magnitude2 = vector2.Magnitude();
	float angle = std::acos(dotProduct / (magnitude1 * magnitude2));

	// Calcular el vector de rotación usando el producto cruz
	VeryReal::Vector3 rotationAxis = vector1.Cross(vector2);

	// Extraer la componente y del vector de rotación
	float rotation_y = rotationAxis.GetY(); // Suponiendo que GetY() devuelve la componente y



	return angle*180/ 3.1415;
}
float Ogreman::OgremanControllerComponent::CalcularAnguloConEjeY(float punto1_x, float punto1_y, float punto2_x, float punto2_y) {
	// Calcular diferencias en coordenadas
	float diferencia_x = punto2_x - punto1_x;
	float diferencia_y = punto2_y - punto1_y;

	// Calcular ángulo usando arcotangente y convertir de radianes a grados
	float angulo = std::atan2(diferencia_x, diferencia_y) * (180.0f / 3.1415);

	return angulo;
}
bool Ogreman::OgremanControllerComponent::InitComponent() {
	trans = GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (trans == nullptr) {
		#ifdef _DEBUG
		std ::cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene TransformComponent\n";
		#endif // DEBUG

		return false;
	}
	animation= GetEntity()->GetComponent<VeryReal::AnimatorComponent>();
	if (animation == nullptr) {
		#ifdef _DEBUG
				std::cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene AnimatorComponent\n";
		#endif // DEBUG
				return false;
	}
	animation->setAnimation("RunTop",true,true);
	animation->setAnimation("RunBase", true, true);
	my_rb= GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (my_rb == nullptr) {
#ifdef _DEBUG
		std::cout << "No se puede añadir el component OgremanControllerComponent dado que la entidad no tiene RigidBodyComponent\n";
#endif // DEBUG
		return false;
	}

	all_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	patrol_nodes = Ogreman::GameManager::Instance()->GetPatrolNode();
	
	if (patrol_nodes.size() < 1) {
	#ifdef _DEBUG
			std ::cout << "No hay nodos de patrulla regitrados\n";
	#endif // DEBUG
		return false;
	}
	current_node = patrol_nodes[current_index];
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (current_node_trans == nullptr) {
	#ifdef _DEBUG
			std::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene TransformComponent "<<patrol_nodes[current_index]->GetID()<<"\n";
	#endif // DEBUG

		return false;
	}
	collider= GetEntity()->GetComponent<VeryReal::ColliderComponent>();
	if (collider == nullptr) {
		if (current_node_trans == nullptr) {
#ifdef _DEBUG
			std ::cout << "No se puede añadir el component OgremanControllerComponent dado que el NodeComponent no tiene ColliderComponent " << patrol_nodes[current_index]->GetID() << "\n";
#endif // DEBUG

			return false;
		}
	}
	current_states = pathfinding;
	std::cout <<"PATROL_NODES " << patrol_nodes.size() << "\n";
	

	VeryReal::Vector3 dif = current_node_trans->GetPosition() - trans->GetPosition();
	
	VeryReal::Vector3 vector_facing = trans->getFacingDirection();
	my_rb->Rotate(VeryReal::Vector3(0, 1, 0),RotationYBetween(vector_facing,dif));
	my_rb->Rotate(VeryReal::Vector3(1,0, 0), 180);

	grid = GameManager::Instance()->GetGris();
	VeryReal::Vector3 v(10, 0, -10);

	GoToLocation(v);
	return true;
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
	VeryReal::Vector3 vec(0,0,0), rot(0,0,0);
	vec = current_node_trans->GetPosition();
	float yaw=0, pitch=0,diff = 0,rota=0,dist=0;

	switch (current_states) {


	case Ogreman::OgremanControllerComponent::stop:
		break;
	case Ogreman::OgremanControllerComponent::patrol:
		dif = dif.Normalize();
		dif *= 2;
		my_rb->SetVelocityLinear(dif);
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
			dif *= 2;
			my_rb->SetVelocityLinear(dif);

		break;
	case Ogreman::OgremanControllerComponent::follow:
		dif_player = dif_player.Normalize();
		dif_player *= 0.01f;
		my_rb->SetVelocityLinear(dif);


		if (dif_player.Magnitude() > 3) {
			RestartPatrol();

		}

	


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
	VeryReal::Vector3 facing = trans->getFacingDirection();
	dif = trans->GetPosition() - current_node_trans->GetPosition();
	my_rb->Rotate(VeryReal::Vector3(0, 1, 0), RotationYBetween(facing, dif));
	/*VeryReal::Vector3 v = my_rb->GetVelocity();
	v *= -1;
	my_rb->SetVelocityLinear(v);*/
}
int  Ogreman::OgremanControllerComponent::GetState() {
	return int(current_states);
}
void Ogreman::OgremanControllerComponent::NextNodePF() {
	current_node = Astar_nodes.front();
	Astar_nodes.pop_front();
	current_node_trans = current_node->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	VeryReal::Vector3 facing = trans->getFacingDirection();
	dif= trans->GetPosition() - current_node_trans->GetPosition();
	my_rb->Rotate(VeryReal::Vector3(0, 1, 0),RotationYBetween(facing, dif));
	facing = trans->getFacingDirection();
	if (Astar_nodes.size() == 0)last_node = true;
}
void Ogreman::OgremanControllerComponent::OnCollisionEnter(VeryReal::Entity* other) {
	std::cout << "\nCHECK COLISION\n";
	if (current_states==patrol && other != nullptr && other->HasComponent("NodeComponent") && other->GetComponent<NodeComponent>()->GetID()==  current_node->GetID()) {
		std::cout << "\nHAY COLISION\n";
		NextNodePT();

	}
	else if (current_states == pathfinding && other!=nullptr &&other->HasComponent("NodeComponent")) {
		if (last_node)RestartPatrol();
		else NextNodePF();


	}
 }
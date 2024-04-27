#include "GridComponent.h"
#include "GameManager.h"
#include "PhysicsManager.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "algorithm"
using namespace Ogreman;
GridComponent::GridComponent() {

}
 void GridComponent::Update(const double& dt) {

}
 NodeComponent* isInList(std::list<NodeComponent*> list, NodeComponent* node) {

	 for (auto c : list) {
		 if (c == node) {
			 return c;
		 }
	 }
	 return nullptr;
 }

 std::list<Ogreman::NodeComponent*> GridComponent::getPathAStar(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition) {

	 std::list<Ogreman::NodeComponent*> path;
	 std::cout << "busco\\n";
	 NodeComponent* src = Vector2Node(InitPos);
	 NodeComponent* dest = Vector2Node(EndPosition);

	 std::list<NodeComponent*>open;
	 std::list<NodeComponent*>closed;
	 open.push_back(src);
	 src->sethCost(0);

	 NodeComponent* current = src;
	 float stimated = 0;
	 std::cout << "hola estoro en while\\n";
	 while (open.size() > 0) {

		// std::sort(open.begin(), open.end());
		 //no me acuerdo como se escribe
		 if (current == dest) {
			 break;
		 }
		 float hendNode = 0;
		 auto conections = current->GetNeighbours();
		 
		 for (auto d : conections) {
			 stimated = current->Gethcost() + current->GetCost();

			 NodeComponent* endNode = isInList(closed, d);
			 
			 NodeComponent* endNode2 = isInList(open, d);
			 if (endNode!=nullptr) {

				 if (endNode->Gethcost() <= stimated)continue;
				 else {
					 hendNode = endNode->Gethcost() + endNode->GetCost();

					 closed.remove(endNode);
				 }
			}
			 else if (endNode2 != nullptr) {

				 if (endNode2->Gethcost() <= stimated)continue;
				 else {
					 hendNode = endNode2->GetCost() + endNode2->GetCost();

				 }
			 }
			 else {
				 //no se que va aqui ...

				 
		/*	
				 tempNode.SetConection(d);
				 tempNode.SetConection(current);
				 tempNode.sethCost(stimated);
				 tempNode.setStimated(stimated + hendNode);*/
				 d->SetConection(current);
				 d->sethCost(stimated);
				 d->setStimated(stimated + hendNode);
				 endNode = d;
				// endNode->SetConection(current);
			 }

			 endNode->SetConection(current);
			 endNode->sethCost(stimated);
			 endNode->setStimated(stimated + hendNode);
			 current = endNode;

		 }
		 open.remove(current);
		 closed.push_back(current);




	 }
	 if (current->GetID() != dest->GetID()) {

		 return path;//algo va mal
	 }
	 else {
		 path.clear();

		 while (current->GetID() != src->GetID()) 
		 {
			 path.push_front(current);
			 current = current->GetConection();
		 }
		 path.push_front(src);
	 }

	 return path;

 }
 NodeComponent* GridComponent::Vector2Node(VeryReal::Vector3 const& vec) {
	 float minimun(INT16_MAX);

	 NodeComponent* node = nullptr;
	 for (auto c : scenes_nodes) {
		 VeryReal::Vector3 dif,res;
		 res = vec;
		 float difd = (res - c->GetEntity()->GetComponent<VeryReal::TransformComponent>()->GetPosition()).Magnitude();
		 if (difd < minimun) {
			 minimun = difd;
			 node = c;
		 }


	 }
	 return node;
 }
 bool GridComponent::InitComponent() {
	 scenes_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	 std::cout << "TAMAÑO SCENES NODES " << scenes_nodes.size() << "\n";
	 for (auto c : scenes_nodes) {
		 //std::list<VeryReal::Entity*> MakeRayCast(VeryReal::Vector3 ray_Start, VeryReal::Vector3 ray_End);

		 VeryReal::TransformComponent* trans = (c->GetEntity())->GetComponent<VeryReal::TransformComponent>();
		 if (trans == nullptr) {
			 std::cerr << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID() << "\n";
			 return false;
		 }
		 else {

			 for (auto d : scenes_nodes) {
				 std::cout << "HOLA"  << "\n";
				 if (c->GetID() != d->GetID()) {//compruebpo que no soy yo mismo
				
					 std::cout << "ADIOS" << "\n";
					 VeryReal::TransformComponent* other = d->GetEntity()->GetComponent<VeryReal::TransformComponent>();
					 if (other == nullptr) {
						 std::cout << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID() << "\n";
						 return false;
					 }
					 
					 c->AddNeighbors(d);
					 c->sethCost((trans->GetPosition() - other->GetPosition()).Magnitude());

					 std::list<VeryReal::Entity*> colision = VeryReal::PhysicsManager::Instance()->MakeRayCast(trans->GetPosition(), other->GetPosition());
					 std::cout << "tamaño lista" << colision.size()<<"\n";
					 if (!colision.empty() && colision.back()->HasComponent("NodeComponent")) {

						 c->AddNeighbors(d);
						 std::cout << " AÑADO ARISTE\n";
					 }


				 }


			 }


		 }
		
		
	 }
	 
	 GameManager::Instance()->RegisterGridComponent(this);
	 return true;

 }
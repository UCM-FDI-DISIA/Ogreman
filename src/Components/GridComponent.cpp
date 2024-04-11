#include "GridComponent.h"
#include "GameManager.h"
#include "PhysicsManager.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "algorithm"
using namespace Ogreman;
GridComponent::GridComponent():grid(0) {

}
 void GridComponent::Update(const double& dt) {

}

 std::vector<Ogreman::NodeComponent*> GridComponent::getPathAStar(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition) {

	 std::vector<Ogreman::NodeComponent*> path;
	 NodeComponent* src = Vector2Node(InitPos);
	 NodeComponent* dest = Vector2Node(EndPosition);

		std::list<NodeComponent*>open;
	 std::list<NodeComponent*>closed;
	 open.push_back(src);
	 NodeComponent* current = src;
	 float current_cost = 0;

	 while (open.size() > 0) {

		 std::sort(open.begin(), open.end());

		 if (current == dest) {
			 break;
		 }

		 auto conections = current->GetNeighbours();
		 for (auto d : conections) {
			 current_cost += d->GetCost();

			

		 }
		 
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
		// res.SetVector(VeryReal::Vector3(abs(res.GetX()), abs(res.GetY()), abs(res.GetX())));
		 if (difd < minimun) {
			 node = c;
		 }


	 }
	 return node;
 }
 bool GridComponent::InitComponent() {
	 scenes_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	
	 for (auto c : scenes_nodes) {
		 std::list<VeryReal::Entity*> MakeRayCast(VeryReal::Vector3 ray_Start, VeryReal::Vector3 ray_End);

		 VeryReal::TransformComponent* trans = (c->GetEntity())->GetComponent<VeryReal::TransformComponent>();
		 if (trans == nullptr) {

			 std::cerr << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID() << "\n";
			 return false;
		 }
		 else {

			 for (auto d : scenes_nodes) {

				 if (c != d) {//compruebpo que no soy yo mismo
					 VeryReal::TransformComponent* other = d->GetEntity()->GetComponent<VeryReal::TransformComponent>();
					 if (other == nullptr) {
						 std::cerr << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID() << "\n";
						 return false;
					 }
					 std::list<VeryReal::Entity*> colision = VeryReal::PhysicsManager::Instance()->MakeRayCast(trans->GetPosition(), other->GetPosition());
					 VeryReal::Entity* ent = colision.back();
					 if (!colision.empty() && ent->HasComponent("NodeComponent")) {

						 c->AddNeighbors(d);

					 }


				 }


			 }


		 }

		 return true;
	 }

 }
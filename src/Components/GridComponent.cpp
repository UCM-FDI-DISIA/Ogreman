#include "GridComponent.h"
#include "GameManager.h"
#include "PhysicsManager.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "algorithm"
#include <set>
using namespace Ogreman;
#include "IndexPQ.h"


GridComponent::GridComponent() :nodes(0) {}

using namespace Ogreman;

 void GridComponent::Update(const double& dt) {

}
 NodeComponent* GridComponent::isInList(std::list<NodeComponent*> list, NodeComponent* node) {
	 for (auto c : list) {
		 if (c == node) {
			 return c;
		 }
	 }
	 return nullptr;
 }

 std::list<NodeComponent*> GridComponent::GetPathDikstra(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition) {
	 std::list<Ogreman::NodeComponent*> path;
	 //std::cout << "busco\\n";
	 NodeComponent* src = Vector2Node(InitPos);
	 NodeComponent* dest = Vector2Node(EndPosition);

	 if (src->GetID() == dest->GetID()) {
		 path.push_back(src);
		 return path;
	 }

	 int origen = 0;
	 std::vector<float> dist(nodes.V(),INT_MAX);
	 std::vector<AristaDirigida<float>> ulti(nodes.V());
	 IndexPQ<float> pq(nodes.V());

	 dist[src->GetID()] = 0;
	 pq.push(src->GetID(), INT_MAX);
	 while (!pq.empty()) {

		 int v = pq.top().elem;
		 pq.pop();
		 for (auto a : nodes.ady(v)) {
			 int v = a.desde(), w = a.hasta();
			 if (dist[w] > dist[v] + a.valor()) {

				 dist[w] = dist[v] + a.valor(); ulti[w] = a;
				 pq.update(w, dist[w]);
			 }
		 }
	 }


	 // recuperamos el camino retrocediendo
	 AristaDirigida<float> a;
	 

	 for (a = ulti[dest->GetID()]; a.desde() != src->GetID(); a = ulti[a.desde()]) {
		 path.push_front(scenes_nodes[a.hasta()]);
	 }
	path.push_front(scenes_nodes[a.hasta()]);
	 path.push_front(scenes_nodes[a.desde()]);
		// cam.push_front(a);


	 //cam.push_front(a);
	
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
 std::pair<bool, std::string> GridComponent::InitComponent() {
	 scenes_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	 nodes = DigrafoValorado<float >(scenes_nodes.size());
	 std::sort(scenes_nodes.begin(), scenes_nodes.end(),
		 [](auto& a, auto& b) { return a->GetID() < b->GetID(); });

	 //Desde un nodo lanzas Raycast a todo los demás por eso los dos For
	 for (auto c : scenes_nodes) {
		 VeryReal::TransformComponent* trans = (c->GetEntity())->GetComponent<VeryReal::TransformComponent>();
		 if (trans == nullptr) {
			 return { false,  "The NodeComponent doesn't have Transform Component, ERROR from GridComponent" };
		 }
		 else {

			 for (auto d : scenes_nodes) {
				 if (c->GetID() != d->GetID()) {//compruebpo que no soy yo mismo
					 VeryReal::TransformComponent* other = d->GetEntity()->GetComponent<VeryReal::TransformComponent>();
					 if (other == nullptr) {
						 return { false,  "The NodeComponent doesn't have Transform Component, ERROR from GridComponent" };
					 }

					 VeryReal::Vector3 origin = trans->GetPosition();
					 VeryReal::Vector3 di = other->GetPosition()-trans->GetPosition();

					 ////VeryReal::Vector3 dest = { 20, 7, 70 };
					 VeryReal::Vector3 dest = trans->GetPosition() + di * 100;

					 auto ents = VeryReal::PhysicsManager::Instance()->MakeRayCast(origin, other->GetPosition());
					//auto ents= VeryReal::PhysicsManager::Instance()->MakeRayCast(trans->GetPosition(), other->GetPosition());
					#ifdef _DEBUG
					 std::cout << "LANZO RAYCAST DE  " << c->GetID() << " a " << d->GetID() << "\n";
					 std::cout << "TAMAÑE LISTE " << ents.size() << "\n";

					#endif // _DEBUG

					 c->sethCost((trans->GetPosition() - other->GetPosition()).Magnitude());
					 float coste = (trans->GetPosition() - other->GetPosition()).Magnitude();
					 
				

					// mystruct d = ents.top();
					 if (ents.size()==1 && ents.top().ent->GetComponent<NodeComponent>() != nullptr && ents.top().ent->GetComponent<NodeComponent>()->GetID() == d->GetID()  ) {
						 #ifdef _DEBUG
						  std::cout << "AÑADO ARISTE DE" << c->GetID() << "  a  " << d->GetID() << "\n";
						 #endif // _DEBUG

						
						 AristaDirigida<float> arista(c->GetID(), d->GetID(), coste);
						 nodes.ponArista(arista);


					 }
				 }
			 }
		 }
	 }


	 GameManager::Instance()->RegisterGridComponent(this);
	 return { true,"GridComponent made correctly" };
 }
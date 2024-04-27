#include "GridComponent.h"
#include "GameManager.h"
#include "PhysicsManager.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "algorithm"
#include <set>
using namespace Ogreman;
GridComponent::GridComponent():nodes(0) {

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

	
 std::list<NodeComponent*> GridComponent::GetPathDfs(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition) {
	 std::list<Ogreman::NodeComponent*> path;
	 std::cout << "busco\\n";
	 NodeComponent* src = Vector2Node(InitPos);
	 NodeComponent* dest = Vector2Node(EndPosition);

	
	 int origen;
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

	 std::list<NodeComponent> cam;
	 // recuperamos el camino retrocediendo
	 AristaDirigida<float> a;
	 for (a = ulti[dest->GetID()]; a.desde() != src->GetID(); a = ulti[a.desde()]) 
	 {
		 path.push_front(scenes_nodes[a.hasta()]);
	 }
	path.push_front(scenes_nodes[a.hasta()]);
	 path.push_front(scenes_nodes[a.desde()]);
		// cam.push_front(a);


	 //cam.push_front(a);
	
	 return path;
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

		

	 }
	 if (current->GetID() != dest->GetID()) {

		 return path;//algo va mal
	 }
	 else {
		 path.clear();
		// path.push_back(dest);
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
	//nodes(scenes_nodes.size());
	nodes = DigrafoValorado<float >(scenes_nodes.size());
	std::sort(scenes_nodes.begin(), scenes_nodes.end(),
		[](auto& a, auto& b) { return a->GetID() < b->GetID(); });

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
					 
					 //c->AddNeighbors(d);
					 c->sethCost((trans->GetPosition() - other->GetPosition()).Magnitude());
					 float coste = (trans->GetPosition() - other->GetPosition()).Magnitude();
					 if ((c->GetID() == 1 && d->GetID() == 0) || (c->GetID() == 0 && d->GetID() == 2) || (c->GetID() == 1 && d->GetID() == 3)) {
						 //AdysDirVal<NodeComponent*> arista;
						 AristaDirigida<float> arista(c->GetID(),d->GetID(),coste);
						 nodes.ponArista(arista);
					 }
					/* std::list<VeryReal::Entity*> colision = VeryReal::PhysicsManager::Instance()->MakeRayCast(trans->GetPosition(), other->GetPosition());
					 std::cout << "tamaño lista" << colision.size()<<"\n";
					 if (!colision.empty() && colision.back()->HasComponent("NodeComponent")) {

						 c->AddNeighbors(d);
						 std::cout << " AÑADO ARISTE\n";
					 }*/


				 }


			 }


		 }
		
		
	 }
	 
	 GameManager::Instance()->RegisterGridComponent(this);
	 return true;

 }
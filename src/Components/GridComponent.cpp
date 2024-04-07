#include "GridComponent.h"
#include "../../projects/GameManager.h"
#include "PhysicsManager.h"
#include "TransformComponent.h"
GridComponent::GridComponent():grid(0) {

}
 void GridComponent::Update(const double& dt) {

}
 bool GridComponent::InitComponent() {
	 scenes_nodes = Ogreman::GameManager::Instance()->GetPathNode();
	 grid = DigrafoValorado<NodeComponent*>(scenes_nodes.size());
	 for (auto c : scenes_nodes) {
		 //  std::list<VeryReal::Entity*> MakeRayCast(VeryReal::Vector3 ray_Start, VeryReal::Vector3 ray_End);
		
		 //VeryReal::TransformComponent* trans = (c->GetEntity())->GetComponent("Transform");
		 //if (trans == nullptr) {

			// std::cerr << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID()<<"\n";
			// return false;
		 //}
		 //else {

			// for (auto d : scenes_nodes) {

			//	 if (c != d){//compruebpo que no soy yo mismo
			//		 VeryReal::TransformComponent* other = d->GetEntity()->GetComponent("Transform");
			//		 if (other == nullptr) {
			//			 std::cerr << "El componente: NodeComponent no tiene el comoponente transform añadido id: " + c->GetID() << "\n";
			//			 return false;
			//		 }
			//		 std::list<VeryReal::Entity*> colision =VeryReal::PhysicsManager::Instance()->MakeRayCast(trans->GetPosition(),other->GetPosition());

			//		 if (!colision.empty() && colision.pop_back()->HasComponent("NodeComponent")) {

			//			 //NodeComponent* OtherNode=colision.pop_back()->GetComponent("NodeComponent");


			//			// AristaDirigida<NodeComponent*> ar(c->GetID(),OtherNode->GetID(),5);//no se que valor darle supongo que lo de sumando la raiz al cuadrado
			//			 
			//			 grid.ponArista(ar);
			//		 }


			//	 }


			// }


		 }

		 return true;
	 }


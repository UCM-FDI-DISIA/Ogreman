#include "NodeComponent.h"
#include "GameManager.h"
using namespace Ogreman;
NodeComponent::NodeComponent():cost(0),hcost(0),iswalkable(false) {

}
bool NodeComponent::InitComponent(bool ispatrol,float cost, float hcost, bool iswalkable,int id) {
	this->ispatrol = ispatrol;
	this->cost = cost;
	this->hcost = hcost;
	this->estimated_cost = cost + hcost;
	this->iswalkable = iswalkable;
	this->id = id;

	Ogreman::GameManager::Instance()->RegisterPathNode(this);
	if (ispatrol)Ogreman::GameManager::Instance()->RegisterPatrolNode(this);
	return true;
 }
NodeComponent::~NodeComponent() {
	
	for (auto neighbor : neighbours) {//borrarme de los demas vecinos
		neighbor->DeleteNeighbors(this);
	}
	neighbours.clear(); 
}

int NodeComponent::GetID() {
	return this->id;
}
void NodeComponent::AddNeighbors(NodeComponent* node) {//en teoria no se usa
	neighbours.push_back(node);
}
void  NodeComponent::DeleteNeighbors(NodeComponent* node) {//en teoria no se usa
	neighbours.remove(node);
}
std::list<NodeComponent*> NodeComponent::GetNeighbours() {
	return neighbours;

}
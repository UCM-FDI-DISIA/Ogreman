#include "NodeComponent.h"
#include "GameManager.h"
#include"Entity.h"

using namespace Ogreman;
NodeComponent::NodeComponent():cost(0),hcost(0),iswalkable(false) {

}
std::pair<bool, std::string> NodeComponent::InitComponent(bool ispatrol,float cost, float hcost, bool iswalkable,int id) {
	this->ispatrol = ispatrol;
	this->cost = cost;
	this->hcost = hcost;
	this->estimated_cost = cost + hcost;
	this->iswalkable = iswalkable;
	this->id = id;

	Ogreman::GameManager::Instance()->RegisterPathNode(this);
	if (ispatrol)Ogreman::GameManager::Instance()->RegisterPatrolNode(this);
	return { true, "InitComponent NodeComponent correct" };
 }


int NodeComponent::GetID() {
	return this->id;
}

NodeComponent::~NodeComponent() {


}
#pragma once
#ifndef NODECOMPONENT
#define NODECOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include <variant>
#include "../Export.h"
namespace Ogreman
{

	class OGREMAN_API NodeComponent : public VeryReal::Component
	{
	public:
		NodeComponent();
		~NodeComponent();
		virtual bool InitComponent(bool ispatrol, float cost, float hcost, bool iswalkable, int id);
		std::list<NodeComponent*> GetNeighbours();
		void AddNeighbors(NodeComponent* node);
		void DeleteNeighbors(NodeComponent* node);
		int GetID();
		inline void setID(int const& i) { this->id = i; }
		inline float Gethcost() { return hcost; }
		inline void sethCost(float h) { hcost = h; }
		inline void setStimated(float c) { estimated_cost =c;}
		inline float GetStimatedCost() { return estimated_cost; }
		inline NodeComponent* GetConection() { return conection; };
		inline void SetConection(NodeComponent* d) { conection = d; }
		
		bool operator<(const NodeComponent& other) const {
			// Compara los costos de los nodos
			return cost < other.cost;
		}
		inline float GetCost() { return cost; }
	protected:
		float estimated_cost = 0, cost = 0, hcost = 0;
		bool iswalkable = false;
		std::list<NodeComponent*> neighbours;
		int id;
		bool ispatrol;
		NodeComponent* conection=nullptr;
	};
}

#endif // !NodeComponent




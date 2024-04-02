#pragma once
#ifndef NODECOMPONENT
#define NODECOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include <variant>s


	class NodeComponent : public VeryReal::Component
	{
	public:
		NodeComponent();
		~NodeComponent();
		virtual bool InitComponent(float cost, float hcost, int iswalkable,int id);
		std::list<NodeComponent*> GetNeighbours();
		void AddNeighbors(NodeComponent* node);
		void DeleteNeighbors(NodeComponent* node);
		int GetID();
	protected:
		float estimated_cost = 0, cost = 0, hcost = 0;
		bool iswalkable = false;
		std::list<NodeComponent*> neighbours;
		int id;
	};



#endif // !NodeComponent




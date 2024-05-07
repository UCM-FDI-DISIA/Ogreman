#pragma once
#ifndef NODECOMPONENT
#define NODECOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include <variant>
#include "../Export.h"

namespace Ogreman {

#pragma warning(disable : 4251)
	
	class OGREMAN_API NodeComponent : public VeryReal::Component {
	public:
		NodeComponent();
		virtual ~NodeComponent();
		std::pair<bool, std::string>  InitComponent(bool ispatrol, float cost, float hcost, bool iswalkable, int id);
		int GetID();
		inline void setID(int const& i) { this->id = i; }
		inline float Gethcost() { return hcost; }
		inline void sethCost(float h) { hcost = h; }
		inline void setStimated(float c) { estimated_cost =c;}
		inline float GetStimatedCost() { return estimated_cost; }
		inline float GetCostsoFar()const { return costsofar; }
		inline void SetCostSoFar(float c) { costsofar = c; }
		bool operator<(const NodeComponent& other) const {
			// Compara los costos de los nodos
			return cost < other.cost;
		}
		inline float GetCost() { return cost; }
		inline bool GetPatrol() { return ispatrol; }

	private:
		float estimated_cost = 0, cost = 0, hcost = 0;
		bool iswalkable = false;
		int id=0;
		bool ispatrol=0;
		float costsofar;

	};

	#pragma warning(default : 4251)
}

#endif // !NodeComponent




#pragma once
#ifndef GRIDCOMPONENT
#define GRIDCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
#include <variant>
namespace 

{
	class NodeComponent;
	class GridComponent : public VeryReal::Component
	{
	public:
		GridComponent();
		virtual ~GridComponent();
		virtual bool InitComponent(std::list<NodeComponent*> nodes);//SE QUE NO VA A IR ASI PERO ESTO ESTA DIFICI



	protected:
		

	};
}


#endif // !GRIDCOMPONENT



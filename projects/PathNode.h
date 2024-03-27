#pragma once
#ifndef PATHNODE
#define PATHNODE
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
namespace OgreMan {
	class PathNode : public VeryReal::Component
	{

	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

	protected:



	};
}


#endif // PATHINGCOMPONENT
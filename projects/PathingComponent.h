#pragma once
#ifndef PATHINGCOMPONENT
#define PATHINGCOMPONENT
#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
namespace OgreMan {
	class PathingComponent : public VeryReal::Component
	{

	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);

	protected:



	};
}


#endif // PATHINGCOMPONENT



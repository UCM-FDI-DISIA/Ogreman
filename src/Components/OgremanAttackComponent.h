#pragma once
#ifndef OGREMANATTACKCOMPONENT
#define OGREMANATTACKCOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
namespace VeryReal {
	class TransformComponent;
}

namespace Ogreman 
{
	
	class OgremanAttackComponent : public VeryReal::Component
	{
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
	private:
		VeryReal::TransformComponent* my_transform;
		VeryReal::TransformComponent* player_transform;
	};
}

#endif


#pragma once
#ifndef OGREMANATTACKCOMPONENT
#define OGREMANATTACKCOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "CreatorComponent.h"
namespace VeryReal 
{
	class TransformComponent;
	class OgremanAttackComponent : public Component
	{
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
	private:
		TransformComponent* my_transform;
		TransformComponent* player_transform;
	};
}

#endif


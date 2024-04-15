#pragma once
#ifndef OGREMANATTACKCOMPONENT
#define OGREMANATTACKCOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "../Export.h"
namespace VeryReal {
	class TransformComponent;
}

namespace Ogreman 
{
	
	class OGREMAN_API OgremanAttackComponent : public VeryReal::Component
	{
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
	private:
		VeryReal::TransformComponent* my_transform = nullptr;
		VeryReal::TransformComponent* player_transform = nullptr;
	};
}

#endif


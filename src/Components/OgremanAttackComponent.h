#pragma once
#ifndef OGREMANATTACKCOMPONENT
#define OGREMANATTACKCOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "../Export.h"
namespace VeryReal {
	class TransformComponent;
	class UITransformComponent;
	class UiSpriteRenderer;
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
		VeryReal::UITransformComponent* player_UI = nullptr;
		VeryReal::UiSpriteRenderer* sprite_renderer_player = nullptr;
		int nAttacks = 0, maxAttacks = 1;
		bool attacking = false;
		float range = 20, delay_scream = 0.5, delay = 0;
	};
}

#endif


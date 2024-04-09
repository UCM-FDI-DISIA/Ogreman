#pragma once
#ifndef OGREMANCONTROLLERCOMPONENT
#define OGREMANCONTROLLERCOMPONENT
#include <Component.h>
#include "NodeComponent.h"
#include "TransformComponent.h"
#include "AnimatorComponent.h"

namespace Ogreman {
	class OgremanControllerComponent :
		public VeryReal::Component
	{
	public:
		OgremanControllerComponent();
		virtual ~OgremanControllerComponent();
		virtual void Update(const double& dt);
		virtual void OnCollisionEnter(VeryReal::Entity* other);
		 bool InitComponent();
	protected:
		enum states { stop, patrol, pathfinding, follow };
		states current_states=stop;
		VeryReal::AnimatorComponent* animation=nullptr;
		VeryReal::TransformComponent* trans=nullptr;
		VeryReal::TransformComponent* current_node_trans = nullptr;
		NodeComponent* current_node;
		std::vector<NodeComponent*> patrol_nodes;
		std::vector<NodeComponent*> all_nodes;
		int current_index;

	};

}

#endif // !OGREMANCONTROLLERCOMPONENT



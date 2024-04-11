#pragma once
#ifndef OGREMANCONTROLLERCOMPONENT
#define OGREMANCONTROLLERCOMPONENT
#include <Component.h>
#include "NodeComponent.h"
#include "TransformComponent.h"
#include "AnimatorComponent.h"
#include "ColliderComponent.h"
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API OgremanControllerComponent :
		public VeryReal::Component
	{
	public:
		OgremanControllerComponent();
		virtual ~OgremanControllerComponent();
		virtual void Update(const double& dt);
		virtual void OnCollisionEnter(VeryReal::Entity* other);
		 bool InitComponent();
		 VeryReal::Vector3 calculateRotationVector(VeryReal::Vector3& sourceVector, VeryReal::Vector3& targetVector);
	protected:
		enum states { stop, patrol, pathfinding, follow };
		states current_states=stop;
		VeryReal::AnimatorComponent* animation=nullptr;
		VeryReal::TransformComponent* trans=nullptr;
		VeryReal::TransformComponent* current_node_trans = nullptr;
		NodeComponent* current_node;
		std::vector<NodeComponent*> patrol_nodes;
		std::vector<NodeComponent*> all_nodes;
		VeryReal::ColliderComponent* collider = nullptr;
		int current_index;
		float rotationSpeed = 0.1f;
		float t = 0;
	};

}

#endif // !OGREMANCONTROLLERCOMPONENT



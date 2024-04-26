#pragma once
#ifndef OGREMANCONTROLLERCOMPONENT
#define OGREMANCONTROLLERCOMPONENT
#include <Component.h>
#include "NodeComponent.h"
#include "TransformComponent.h"
#include "AnimatorComponent.h"
#include "GridComponent.h"
#include "ColliderComponent.h"
#include "../Export.h"
#include "RigidBodyComponent.h"

#pragma warning(disable : 4251)

namespace Ogreman {
	class OGREMAN_API OgremanControllerComponent : public VeryReal::Component {
	public:
		OgremanControllerComponent();
		virtual ~OgremanControllerComponent();
		virtual void Update(const double& dt);
		virtual void OnCollisionEnter(VeryReal::Entity* other);
		 bool InitComponent();
		float  CalculateRotationVector(VeryReal::Vector3& from, VeryReal::Vector3& to);
		 void setPlayerTransform(VeryReal::TransformComponent* t);
		 void SetState(int state);
		 int  GetState();
	protected:
		enum states { stop, patrol, pathfinding, follow };
		states current_states=stop;
		VeryReal::AnimatorComponent* animation=nullptr;
		VeryReal::TransformComponent* trans=nullptr;
		VeryReal::TransformComponent* current_node_trans = nullptr;
		VeryReal::TransformComponent* player_trns = nullptr;
		GridComponent* grid = nullptr;
		NodeComponent* current_node = nullptr;
		std::list<NodeComponent*> Astar_nodes;
		std::vector<NodeComponent*> patrol_nodes;
		std::vector<NodeComponent*> all_nodes;
		VeryReal::ColliderComponent* collider = nullptr;
		VeryReal::RigidBodyComponent* my_rb;
		int current_index;
		float rotationSpeed = 0.1f;
		float t = 0;
		bool once = false;
	};
}

#pragma warning(default : 4251)

#endif // !OGREMANCONTROLLERCOMPONENT
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
		void GoToLocation(VeryReal::Vector3& to);
		 bool InitComponent();
		 float CalcularAnguloConEjeY(float punto1_x, float punto1_y, float punto2_x, float punto2_y);
		 void setPlayerTransform(VeryReal::TransformComponent* t);
		 void SetState(int state);
		 int  GetState();
		 void RestartPatrol();
		 void NextNodePF();
		 void NextNodePT();
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
		VeryReal::RigidBodyComponent* my_rb = nullptr;
		VeryReal::Vector3 dif;
		int current_index;
		float rotationSpeed = 0.1f;
		float t = 0;
		bool last_node = false;


		float rotation_y = 0;
	};
}

#pragma warning(default : 4251)

#endif // !OGREMANCONTROLLERCOMPONENT
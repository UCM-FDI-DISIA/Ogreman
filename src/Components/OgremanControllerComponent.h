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
		 bool InitComponent(float alignmentWeight, float cohesionWeight, float separationWeight ,float maxSpeed, float separationDistance, float min_dist_follow, float max_dist_follow);
		 void setPlayerTransform(VeryReal::TransformComponent* t);
		 void SetState(int state);
		 int  GetState();
		 void RestartPatrol();
		 void NextNodePF();
		 void NextNodePT();

		 VeryReal::Vector3 align();
		 VeryReal::Vector3 cohere();
			 VeryReal::Vector3 separate();
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


		// Parámetros de Flocking
		float alignmentWeight = 0.1f; // Peso de la alineación
		float cohesionWeight = 0.1f; // Peso de la cohesión
		float separationWeight = 0.1f; // Peso de la separación
		float maxSpeed = 0.5f; // Velocidad máxima del ogro
		float separationDistance = 2.0f;


		float min_dist_follow = 50, max_dist_follow = 100;
	};
}

#pragma warning(default : 4251)

#endif // !OGREMANCONTROLLERCOMPONENT
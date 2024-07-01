#pragma once
#ifndef OGREMANCONTROLLERCOMPONENT
#define OGREMANCONTROLLERCOMPONENT
#include <Component.h>
#include <Entity.h>
#include "../Export.h"
#include "NodeComponent.h"
#include "GridComponent.h"
#include "SmokeComponent.h"

#pragma warning(disable : 4251)
using namespace Ogreman;
using namespace VeryReal;

namespace VeryReal {
    class Vector3;
    class RigidBodyComponent;
    class ColliderComponent;
    class AnimatorComponent;
    class TransformComponent;
}

namespace Ogreman {
    class OGREMAN_API OgremanControllerComponent : public VeryReal::Component {
    public:
        OgremanControllerComponent();
        virtual ~OgremanControllerComponent();
        virtual void Update(const double& dt);
        virtual void OnCollisionEnter(VeryReal::Entity* other);
        std::pair<bool, std::string> GoToLocation(VeryReal::Vector3& to);
        std::pair<bool, std::string> InitComponent(float alignmentWeight, float cohesionWeight, float separationWeight, float maxSpeed, float separationDistance, float min_dist_follow, float max_dist_follow);
        void setPlayerTransform(VeryReal::TransformComponent* t);
        void SetState(int state);
        int GetState();
        void RestartPatrol();
        void NextNodePF();
        void NextNodePT();

        VeryReal::Vector3 align();
        VeryReal::Vector3 cohere();
        VeryReal::Vector3 separate();

    protected:
        enum states { stop, patrol, pathfinding, follow };
        states current_states = stop;
        VeryReal::AnimatorComponent* animation = nullptr;
        VeryReal::TransformComponent* trans = nullptr;
        VeryReal::TransformComponent* current_node_trans = nullptr;
        VeryReal::TransformComponent* player_trns = nullptr;
        Ogreman::GridComponent* grid = nullptr;
        Ogreman::NodeComponent* current_node = nullptr;
        std::list<Ogreman::NodeComponent*> Astar_nodes;
        std::vector<Ogreman::NodeComponent*> patrol_nodes;
        std::vector<Ogreman::NodeComponent*> all_nodes;
        VeryReal::ColliderComponent* collider = nullptr;
        VeryReal::RigidBodyComponent* my_rb = nullptr;
        VeryReal::Vector3 dif;
        int current_index;
        float rotationSpeed = 0.1f;
        float t = 0;
        bool last_node = false;

        int numB = 0;
        float rotation_y = 0;

        VeryReal::Entity* smoke = nullptr;

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

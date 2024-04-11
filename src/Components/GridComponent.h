#pragma once
#ifndef GRIDCOMPONENT 
#define GRIDCOMPONENT
#include <Component.h>
#include "DigrafoValorado.h"
#include "NodeComponent.h"
#include "../Export.h"
#include "Vector3.h"
namespace Ogreman
{
    class OGREMAN_API GridComponent :
        public VeryReal::Component
    {
    public:
        GridComponent();
        virtual void Update(const double& dt);
        virtual bool InitComponent();
        std::vector<Ogreman::NodeComponent*> getPathAStar(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition);
        NodeComponent* Vector2Node(VeryReal::Vector3 const& vec);
    protected:
        DigrafoValorado<Ogreman::NodeComponent*> grid;
        std::vector<Ogreman::NodeComponent*>scenes_nodes;
    };
}

#endif // !GRIDCOMPONENT 




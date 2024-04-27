#pragma once
#ifndef GRIDCOMPONENT 
#define GRIDCOMPONENT
#include <Component.h>
#include "DigrafoValorado.h"
#include "NodeComponent.h"
#include "../Export.h"
#include "Vector3.h"
#include "IndexPQ.h"

#pragma warning(disable : 4251)

namespace Ogreman
{
    class OGREMAN_API GridComponent :
        public VeryReal::Component
    {
    public:
        GridComponent();
        virtual void Update(const double& dt);
        virtual bool InitComponent();
        std::list<Ogreman::NodeComponent*> getPathAStar(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition);
        NodeComponent* Vector2Node(VeryReal::Vector3 const& vec);
       
        std::list<NodeComponent*> GetPathDfs(VeryReal::Vector3 const& InitPos, VeryReal::Vector3 const& EndPosition);

    protected:
        //DigrafoValorado<Ogreman::NodeComponent*> grid;
        std::vector<Ogreman::NodeComponent*>scenes_nodes;
        DigrafoValorado<float> nodes;
    };
}

#pragma warning(default : 4251)

#endif // !GRIDCOMPONENT 




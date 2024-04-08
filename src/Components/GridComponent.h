#pragma once
#ifndef GRIDCOMPONENT 
#define GRIDCOMPONENT
#include <Component.h>
#include "DigrafoValorado.h"
#include "NodeComponent.h"
namespace Ogreman
{
    class GridComponent :
        public VeryReal::Component
    {
    public:
        GridComponent();
        virtual void Update(const double& dt);
        virtual bool InitComponent();
    protected:
        DigrafoValorado<Ogreman::NodeComponent*> grid;
        std::list<Ogreman::NodeComponent*>scenes_nodes;
    };
}

#endif // !GRIDCOMPONENT 




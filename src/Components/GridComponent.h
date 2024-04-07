#pragma once
#ifndef GRIDCOMPONENT 
#define GRIDCOMPONENT
#include <Component.h>
#include "DigrafoValorado.h"
#include "NodeComponent.h"
class GridComponent :
    public VeryReal::Component
{
public:
    GridComponent();
    virtual void Update(const double& dt);
    virtual bool InitComponent();
protected:
    DigrafoValorado<NodeComponent*> grid;
    std::list<NodeComponent*>scenes_nodes;
};
#endif // !GRIDCOMPONENT 




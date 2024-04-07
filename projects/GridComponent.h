#pragma once
#ifndef GRIDCOMPONENT 
#define GRIDCOMPONENT
#include <Component.h>
#include ""
class GridComponent :
    public VeryReal::Component
{
public:
    GridComponent();
    virtual void Update(const double& dt);
protected:

};
#endif // !GRIDCOMPONENT 




#include "CreatorOgremanAttackComponent.h"
#include "OgremanAttackComponent.h"
VeryReal::Component* VeryReal::CreatorOgremanAttackComponent::CreatorSpecificComponent() {
    OgremanAttackComponent* oa = new OgremanAttackComponent();

    if (!oa->InitComponent())
        return nullptr;
    else
        return oa;
}

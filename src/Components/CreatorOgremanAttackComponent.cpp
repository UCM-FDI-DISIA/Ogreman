#include "CreatorOgremanAttackComponent.h"
#include "OgremanAttackComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanAttackComponent::CreatorSpecificComponent() {
    return new OgremanAttackComponent();
}

std::pair<bool, std::string>  Ogreman::CreatorOgremanAttackComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::OgremanAttackComponent* oa = static_cast<Ogreman::OgremanAttackComponent*>(c);

    return oa->InitComponent();
       
}

std::pair<bool, std::string>  Ogreman::CreatorOgremanAttackComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "" };
}

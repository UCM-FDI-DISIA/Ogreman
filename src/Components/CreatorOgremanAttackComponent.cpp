#include "CreatorOgremanAttackComponent.h"
#include "OgremanAttackComponent.h"
VeryReal::Component* Ogreman::CreatorOgremanAttackComponent::CreatorSpecificComponent() {
    return new OgremanAttackComponent();
}

void Ogreman::CreatorOgremanAttackComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::OgremanAttackComponent* oa = static_cast<Ogreman::OgremanAttackComponent*>(c);

    if (!oa->InitComponent()) {
        // Gestion de error
    }
       
}

void Ogreman::CreatorOgremanAttackComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}

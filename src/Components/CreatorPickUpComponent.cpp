#include "CreatorPickUpComponent.h"
#include "PickUpComponent.h"

VeryReal::Component* Ogreman::CreatorPickUpComponent::CreatorSpecificComponent() {
    return new PickUpComponent();
}

void Ogreman::CreatorPickUpComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::PickUpComponent* pick_comp = static_cast<Ogreman::PickUpComponent*>(c);

    if (!pick_comp->InitComponent()) {
        //Gestion de error
    }
        
}

void Ogreman::CreatorPickUpComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
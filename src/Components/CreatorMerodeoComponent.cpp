#include "CreatorMerodeoComponent.h"
#include "MerodeoMovementComponent.h"

VeryReal::Component* Ogreman::CreatorMerodeoComponent::CreatorSpecificComponent() {
    return new Ogreman::MerodeoMovementComponent();
}

void Ogreman::CreatorMerodeoComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::MerodeoMovementComponent* mc = static_cast<Ogreman::MerodeoMovementComponent*>(c);

    if (!mc->InitComponent()) {
        // Gestion de error
    }
}

void Ogreman::CreatorMerodeoComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}

#include "CreatorPlayerInteractionComponent.h"
#include "PlayerInteractionComponent.h"

VeryReal::Component* Ogreman::CreatorPlayerInteractionComponent::CreatorSpecificComponent() {
    return new PlayerInteractionComponent();
}
void Ogreman::CreatorPlayerInteractionComponent::SpecificInitComponent(VeryReal::Component* c) {
    PlayerInteractionComponent* play_int = static_cast<PlayerInteractionComponent*>(c);

    if (!play_int->InitComponent()) {
        // Gestion de error
    }
}

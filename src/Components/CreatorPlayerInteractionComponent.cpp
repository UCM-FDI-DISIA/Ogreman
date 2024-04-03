#include "CreatorPlayerInteractionComponent.h"
#include "PlayerInteractionComponent.h"

VeryReal::Component* VeryReal::CreatorPlayerInteractionComponent::CreatorSpecificComponent() {
    PlayerInteractionComponent* play_int = new PlayerInteractionComponent();

    if (!play_int->InitComponent())
        return nullptr;
    else
        return play_int;
}

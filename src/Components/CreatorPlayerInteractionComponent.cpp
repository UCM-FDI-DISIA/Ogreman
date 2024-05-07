#include "CreatorPlayerInteractionComponent.h"
#include "PlayerInteractionComponent.h"

VeryReal::Component* Ogreman::CreatorPlayerInteractionComponent::CreatorSpecificComponent() {
    return new PlayerInteractionComponent();
}
std::pair<bool, std::string> Ogreman::CreatorPlayerInteractionComponent::SpecificInitComponent(VeryReal::Component* c) {
    PlayerInteractionComponent* play_int = static_cast<PlayerInteractionComponent*>(c);

    return play_int->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorPlayerInteractionComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, " i" };
}

#include "CreatorMenuButtonComponent.h"
#include "MenuButtonComponent.h"

VeryReal::Component* Ogreman::CreatorMenuButtonComponent::CreatorSpecificComponent()
{
    return new MenuButtonComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMenuButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::MenuButtonComponent* menubutton_comp = static_cast<Ogreman::MenuButtonComponent*>(c);
    return menubutton_comp->InitComponent();
}

std::pair<bool, std::string> Ogreman::CreatorMenuButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, " " };
}
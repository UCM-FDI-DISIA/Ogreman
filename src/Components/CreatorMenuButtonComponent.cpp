#include "CreatorMenuButtonComponent.h"
#include "MenuButtonComponent.h"

VeryReal::Component* Ogreman::CreatorMenuButtonComponent::CreatorSpecificComponent()
{
    return new MenuButtonComponent();
}

void Ogreman::CreatorMenuButtonComponent::SpecificInitComponent(VeryReal::Component* c)
{
    Ogreman::MenuButtonComponent* menubutton_comp = static_cast<Ogreman::MenuButtonComponent*>(c);

    if (!menubutton_comp->InitComponent()) {

    }
}

void Ogreman::CreatorMenuButtonComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
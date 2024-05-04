#include "CreatorShowImageComponent.h"
#include "ShowImageComponent.h"

VeryReal::Component* Ogreman::CreatorShowImageComponent::CreatorSpecificComponent() {
    return new ShowImageComponent();
}

void Ogreman::CreatorShowImageComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::ShowImageComponent* showImage_comp = static_cast<Ogreman::ShowImageComponent*>(c);
    float ttoshow;
    if (std::holds_alternative<float>(parameters_map.at("ttoshow")->GetVariant())) {
        ttoshow = std::get<float>(parameters_map.at("ttoshow")->GetVariant());
    }
    bool b = showImage_comp->InitComponent(ttoshow);
    if (!b) {
        // Gestion de error
    }
}

void Ogreman::CreatorShowImageComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
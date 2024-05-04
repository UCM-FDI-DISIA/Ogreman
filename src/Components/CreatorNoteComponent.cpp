#include "CreatorNoteComponent.h"
#include "NoteComponent.h"

VeryReal::Component* Ogreman::CreatorNoteComponent::CreatorSpecificComponent() {
    return new NoteComponent();
}

void Ogreman::CreatorNoteComponent::SpecificInitComponent(VeryReal::Component* c) {
    Ogreman::NoteComponent* note_comp = static_cast<Ogreman::NoteComponent*>(c);

    if (!note_comp->InitComponent(" ")) {
        // Gestion de error
    }
}

void Ogreman::CreatorNoteComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {

}
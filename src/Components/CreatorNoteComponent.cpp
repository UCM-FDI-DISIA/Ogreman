#include "CreatorNoteComponent.h"
#include "NoteComponent.h"

VeryReal::Component* VeryReal::CreatorNoteComponent::CreatorSpecificComponent() {
    NoteComponent* note_comp = new NoteComponent();

    if (!note_comp->InitComponent())
        return nullptr;
    else
        return note_comp;
}
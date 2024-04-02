#include "NoteComponent.h"
bool VeryReal::NoteComponent::InitComponent(std::string text_) {
	text = text_;
	pickedUp = false;
	return true;
}
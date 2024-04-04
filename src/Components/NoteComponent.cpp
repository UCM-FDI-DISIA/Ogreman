#include "NoteComponent.h"
bool Ogreman::NoteComponent::InitComponent(std::string text_) {
	text = text_;
	pickedUp = false;
	return true;
}
#include "NoteComponent.h"
bool Ogreman::NoteComponent::InitComponent(std::string text_) {
	text = text_;
	pickedUp = false;
	return true;
}

std::string Ogreman::NoteComponent::getText() {
	return text;
}
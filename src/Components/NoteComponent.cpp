#include "NoteComponent.h"
bool Ogreman::NoteComponent::InitComponent(std::string text) {
	textt = text;
	pickedUp = false;
	return true;
}

std::string Ogreman::NoteComponent::getText() {
	return textt;
}
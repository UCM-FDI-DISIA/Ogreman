#include "NoteComponent.h"
std::pair<bool, std::string> Ogreman::NoteComponent::InitComponent(std::string text) {
	textt = text;
	pickedUp = false;
	return { true,"Initcomponent correct NoteComponent" };
}

std::string Ogreman::NoteComponent::getText() {
	return textt;
}
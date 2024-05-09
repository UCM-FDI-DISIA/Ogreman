#include "NoteComponent.h"
#include "AudioSourceComponent.h"
#include "Entity.h"
std::pair<bool, std::string> Ogreman::NoteComponent::InitComponent(std::string text) {
	textt = text;
	pickedUp = false;
	my_audio_source = this->GetEntity()->GetComponent<VeryReal::AudioSourceComponent>();
	return { true,"Initcomponent correct NoteComponent" };
}

std::string Ogreman::NoteComponent::getText() {
	return textt;
}

void Ogreman::NoteComponent::PlayPickUpSound()
{
	my_audio_source->Play();
}


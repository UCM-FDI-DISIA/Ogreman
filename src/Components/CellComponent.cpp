#include "CellComponent.h"
#include "AudioSourceComponent.h"
#include "Entity.h"

std::pair<bool, std::string> Ogreman::CellComponent::InitComponent() {
	pickedUp = false;
	my_audio_source = this->GetEntity()->GetComponent<VeryReal::AudioSourceComponent>();
	return { true, "CellComponent Inicialize" };
}

void Ogreman::CellComponent::PlayPickUpSound()
{
	my_audio_source->Play();
}

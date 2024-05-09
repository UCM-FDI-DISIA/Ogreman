#include "PlayButtonComponent.h"
#include "AudioManager.h"
#include "GameManager.h"

void Ogreman::PlayButtonComponent::Action()
{
	VeryReal::AM().StopEverySound();
	Ogreman::GameManager::Instance()->Play();		
}

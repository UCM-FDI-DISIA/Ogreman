#include "ControlsButtonComponent.h"
#include "AudioManager.h"
#include "GameManager.h"

void Ogreman::ControlsButtonComponent::Action()
{
	VeryReal::AM().StopEverySound();
	Ogreman::GameManager::Instance()->Controls();
}

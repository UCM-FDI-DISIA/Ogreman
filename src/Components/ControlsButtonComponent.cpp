#include "ControlsButtonComponent.h"
#include "GameManager.h"

void Ogreman::ControlsButtonComponent::Action()
{
	Ogreman::GameManager::Instance()->Controls();
}

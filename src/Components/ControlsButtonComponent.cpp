#include "ControlsButtonComponent.h"
#include "GameManager.h"

void Ogreman::ControlsButtonComponent::accion()
{
	Ogreman::GameManager::Instance()->Controls();
}

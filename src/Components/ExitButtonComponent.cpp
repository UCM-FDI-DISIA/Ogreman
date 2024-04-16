#include "ExitButtonComponent.h"
#include "InputManager.h"

bool Ogreman::ExitButtonComponent::InitComponent()
{
	return true;
}

void Ogreman::ExitButtonComponent::accion()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}

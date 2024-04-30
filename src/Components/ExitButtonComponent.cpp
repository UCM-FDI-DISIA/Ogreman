#include "ExitButtonComponent.h"
#include "InputManager.h"

void Ogreman::ExitButtonComponent::accion()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}

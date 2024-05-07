#include "ExitButtonComponent.h"
#include "InputManager.h"

void Ogreman::ExitButtonComponent::Action()
{
	VeryReal::InputManager::Instance()->Quit(); // Salir de la app
}

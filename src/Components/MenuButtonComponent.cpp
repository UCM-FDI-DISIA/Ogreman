#include "MenuButtonComponent.h"
#include "GameManager.h"

void Ogreman::MenuButtonComponent::accion()
{
	Ogreman::GameManager::Instance()->Menu();
}
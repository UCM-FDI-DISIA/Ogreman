#include "MenuButtonComponent.h"
#include "GameManager.h"

void Ogreman::MenuButtonComponent::Action()
{
	Ogreman::GameManager::Instance()->Menu();
}
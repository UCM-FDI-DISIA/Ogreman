#include "MenuButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"
#include "GameManager.h"

void Ogreman::MenuButtonComponent::accion()
{
	Ogreman::GameManager::Instance()->Menu();
}
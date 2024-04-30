#include "MenuButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"

bool Ogreman::MenuButtonComponent::InitComponent()
{
	return true;
}

void Ogreman::MenuButtonComponent::accion()
{
	VeryReal::SceneManager::Instance()->RemoveScene("EndScene"); // RemoveScene
	VeryReal::SceneManager::Instance()->AddScene("MenuScene", true); // AddScene
	VeryReal::ScriptManager::Instance()->NewScene("MenuScene");
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene"); // ReadScene
}
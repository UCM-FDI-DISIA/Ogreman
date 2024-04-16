#include "PlayButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"

bool Ogreman::PlayButtonComponent::InitComponent()
{
	return true;
}

void Ogreman::PlayButtonComponent::accion()
{
	VeryReal::SceneManager::Instance()->RemoveScene("MainMenu"); // RemoveScene
	VeryReal::SceneManager::Instance()->AddScene("HouseScene", true); // AddScene
	VeryReal::ScriptManager::Instance()->Init("HouseScene");
	VeryReal::ScriptManager::Instance()->ReadScene("HouseScene"); // ReadScene
}

#include "PlayButtonComponent.h"
#include "SceneManager.h"
#include "ScriptManager.h"
#include "GameManager.h"

void Ogreman::PlayButtonComponent::accion()
{
	Ogreman::GameManager::Instance()->Play();
}

#include "GameManager.h"
#include "Scene.h"
#include "Entity.h"
#include "TransformComponent.h"
#include <iostream>
#include "ScriptManager.h"
#include "PhysicsManager.h"
#include "ErrorManager.h"
using namespace Ogreman;
 GameManager::~GameManager() {

}
std::pair<bool,std::string> GameManager::Start() {
	return VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);
}

void GameManager::Menu() {
	std::string currentScene = VeryReal::SceneManager::Instance()->GetActiveScene()->GetName();
	if (currentScene == "WinScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("WinScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("WinScene", true);
	}
	else if (currentScene == "LoseScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("LoseScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("LoseScene", true);
	}
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true));
}
void GameManager::Pause() {
	
}
void GameManager::Controls()
{
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("ControlsScene", true));
}
void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("ControlsScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("ControlsScene", true);
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("HouseScene", true));
#ifdef _DEBUG
	//VeryReal::PhysicsManager::Instance()->SeeDebugColliders(false);
#endif // DEBUG


}

void Ogreman::GameManager::NextLevel() {
	VeryReal::SceneManager::Instance()->ActivationScene("HouseScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("HouseScene", true);

	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("JardinScene", true));
	VeryReal::ScriptManager::Instance()->ReadPrefabs();
	VeryReal::ScriptManager::Instance()->ExposeFunctionsVoidIntToLua("GenerateTree", GenerateTree);
	VeryReal::ScriptManager::Instance()->ReadFunction("GenerateTreeLua", 10);
}

void GameManager::Win() {
	VeryReal::SceneManager::Instance()->ActivationScene("JardinScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("JardinScene", true);
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("WinScene", true));
}
void GameManager::Lose() {
	std::string currentScene = VeryReal::SceneManager::Instance()->GetActiveScene()->GetName();
	if (currentScene == "HouseScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("HouseScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("HouseScene", true);
	}
	else if (currentScene == "JardinScene") {
		VeryReal::SceneManager::Instance()->ActivationScene("JardinScene", false);
		VeryReal::SceneManager::Instance()->EliminationScene("JardinScene", true);
	}
	VeryReal::ErrorManager::Instance()->canBeError(VeryReal::ScriptManager::Instance()->ReadScene("LoseScene", true));
}

void GameManager::GenerateTree(int n) {
	std::string name = "Pino" + std::to_string(n);
	std::cout << name << std::endl;
	VeryReal::Entity* e = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabPino", name);
	e->GetComponent<VeryReal::TransformComponent>()->SetPosition(VeryReal::Vector3(0 + 10 * n, 0, 0));
}
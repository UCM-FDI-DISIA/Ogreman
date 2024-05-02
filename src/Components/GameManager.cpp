#include "GameManager.h"
#include "Scene.h"
#include "Entity.h"
#include "TransformComponent.h"
#include <iostream>
using namespace Ogreman;
 GameManager::~GameManager() {

}
void GameManager::Start() {
	//aqu� a�adiremos todas las escena del juego(Menu, Pausa, Juego,Win , Loose) y dejaremos activa la del Menu Inicial
	VeryReal::SceneManager::Instance()->AddScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->AddScene("PlayScene", false);
	VeryReal::SceneManager::Instance()->AddScene("PauseScene", false);
	VeryReal::SceneManager::Instance()->AddScene("WinScene", false);
	VeryReal::SceneManager::Instance()->AddScene("LoseScene", false);
	
}
void GameManager::Update(const double& dt) {
	VeryReal::SceneManager::Instance()->Update(dt);
}
void GameManager::Menu() {
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", true);
	VeryReal::SceneManager::Instance()->ActivationScene("PlayScene", false);
	VeryReal::SceneManager::Instance()->ActivationScene("PauseScene", false);
	VeryReal::SceneManager::Instance()->ActivationScene("WinScene", false);
	VeryReal::SceneManager::Instance()->ActivationScene("LoseScene", false);
}
void GameManager::Pause() {
	VeryReal::SceneManager::Instance()->ActivationScene("PauseScene", true);
	VeryReal::SceneManager::Instance()->ActivationScene("PlayScene", false);
}
void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("PlayScene", true);
	VeryReal::SceneManager::Instance()->ActivationScene("PauseScene", false);
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
}
void GameManager::Win() {
	VeryReal::SceneManager::Instance()->ActivationScene("WinScene", true);
	VeryReal::SceneManager::Instance()->ActivationScene("PlayScene", false);
}
void GameManager::Loose() {
	VeryReal::SceneManager::Instance()->ActivationScene("LoseScene", true);
	VeryReal::SceneManager::Instance()->ActivationScene("PlayScene", false);
}

void GameManager::HolaLua() {
	std::cout << "Hola Lua\n";
}

void GameManager::GenerateTree(int n) {
	std::string name = "Pino" + std::to_string(n);
	std::cout << name << std::endl;
	VeryReal::Entity* e = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabPino", name);

	// Falta asignar una posicion aleatoria
	e->GetComponent<VeryReal::TransformComponent>()->SetPosition(VeryReal::Vector3(0, 0, 0));
}
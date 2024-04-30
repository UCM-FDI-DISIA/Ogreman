#include "GameManager.h"
#include "Scene.h"
using namespace Ogreman;
 GameManager::~GameManager() {

}
void GameManager::Start() {
	//aquí añadiremos todas las escena del juego(Menu, Pausa, Juego,Win , Loose) y dejaremos activa la del Menu Inicial
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
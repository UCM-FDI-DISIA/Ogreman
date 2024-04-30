#include "GameManager.h"
#include "Scene.h"
using namespace Ogreman;
 GameManager::~GameManager() {

}
void GameManager::Start() {
	//aquí añadiremos todas las escena del juego(Menu, Pausa, Juego,Win , Loose) y dejaremos activa la del Menu Inicial
	VeryReal::SceneManager::Instance()->AddScene("Menu", false);
	VeryReal::SceneManager::Instance()->AddScene("Play", false);
	VeryReal::SceneManager::Instance()->AddScene("Pause", false);
	VeryReal::SceneManager::Instance()->AddScene("Win", false);
	VeryReal::SceneManager::Instance()->AddScene("Loose", false);
	
}
void GameManager::Update(const double& dt) {
	VeryReal::SceneManager::Instance()->Update(dt);
}
void GameManager::Menu() {
	VeryReal::SceneManager::Instance()->ActivationScene("Menu", true);
	VeryReal::SceneManager::Instance()->ActivationScene("Play", false);
	VeryReal::SceneManager::Instance()->ActivationScene("Pause", false);
	VeryReal::SceneManager::Instance()->ActivationScene("Win", false);
	VeryReal::SceneManager::Instance()->ActivationScene("Loose", false);
}
void GameManager::Pause() {
	VeryReal::SceneManager::Instance()->ActivationScene("Pause", true);
	VeryReal::SceneManager::Instance()->ActivationScene("Play", false);
}
void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("Play", true);
	VeryReal::SceneManager::Instance()->ActivationScene("Pause", false);
	VeryReal::SceneManager::Instance()->ActivationScene("Menu", false);
}
void GameManager::Win() {
	VeryReal::SceneManager::Instance()->ActivationScene("Win", true);
	VeryReal::SceneManager::Instance()->ActivationScene("Play", false);
}
void GameManager::Loose() {
	VeryReal::SceneManager::Instance()->ActivationScene("Loose", true);
	VeryReal::SceneManager::Instance()->ActivationScene("Play", false);
}
#include "GameManager.h"
#include "Scene.h"
#include "Entity.h"
#include "TransformComponent.h"
#include <iostream>
#include "ScriptManager.h"
#include "PhysicsManager.h"
using namespace Ogreman;
 GameManager::~GameManager() {

}
void GameManager::Start() {
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);
}
void GameManager::Update(const double& dt) {
	VeryReal::SceneManager::Instance()->Update(dt);
}
void GameManager::Menu() {
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);
}
void GameManager::Pause() {
	
}
void GameManager::Controls()
{
	VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);
	VeryReal::ScriptManager::Instance()->ReadScene("ControlsScene", true);
}
void GameManager::Play() {
	VeryReal::SceneManager::Instance()->ActivationScene("ControlsScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("ControlsScene", true);
	/*VeryReal::SceneManager::Instance()->ActivationScene("MenuScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("MenuScene", true);*/
	VeryReal::ScriptManager::Instance()->ReadScene("HouseScene", true);
	
	
	//Hace que no se actualicen los collider de los rigidbodies tras haber sido instanciados
	//Descomentar si queremos ver cajas en movimiento
#ifdef _DEBUG
	//VeryReal::PhysicsManager::Instance()->SeeDebugColliders(false);
#endif // DEBUG


}
void GameManager::Win() {
	VeryReal::ScriptManager::Instance()->ReadScene("WinScene", true);
	/*VeryReal::SceneManager::Instance()->ActivationScene("HouseScene", false);
	VeryReal::SceneManager::Instance()->EliminationScene("HouseScene", true);
	VeryReal::ScriptManager::Instance()->ReadScene("MenuScene", true);*/
}
void GameManager::Lose() {
	VeryReal::ScriptManager::Instance()->ReadScene("LoseScene", true);
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
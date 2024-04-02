#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
#include <PhysicsManager.h>

bool VeryReal::PickUpComponent::InitComponent() {
	player_transform = SceneManager::Instance()->GetScene("Play")->GetEntity("player")->GetComponent<TransformComponent>("TransformComponent");
	return true;
}

void VeryReal::PickUpComponent::Update(const double& dt) {
	bool lista_de_colisionados = PhysicsManager::MakeRayCast(player_transform->GetPosition(), player_transform->GetPosition() + Vector3(1000,0,0));
}
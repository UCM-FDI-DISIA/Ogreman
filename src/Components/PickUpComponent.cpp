#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "PlayerInteractionComponent.h"
#include <SceneManager.h>
#include <Scene.h>
#include <PhysicsManager.h>


bool Ogreman::PickUpComponent::InitComponent() {
	player_transform = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("player")->GetComponent<VeryReal::TransformComponent>("TransformComponent");
	return true;
}

void Ogreman::PickUpComponent::Update(const double& dt) {
	auto collided_list = VeryReal::PhysicsManager::Instance()->MakeRayCast(player_transform->GetPosition(), player_transform->GetPosition() + VeryReal::Vector3(1000,0,0));
	std::cout << "N colisionados: " << collided_list.size() << "\n";
	for (auto elem_collided : collided_list) {
		/*if (elem_collided->GetComponent<NoteComponent>("NoteComponent") || elem_collided->GetComponent<CellComponent>("CellComponent")) {

		}*/
	}
}

void Ogreman::PickUpComponent::GetElement() {
	// Raycast
	// Detectar si es una nota o una pila 
	// LLamar al playerInteraction para hacer GetCell() o GetNote()
	// Borrar
}
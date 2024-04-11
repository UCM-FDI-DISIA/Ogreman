#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "PlayerInteractionComponent.h"
#include <SceneManager.h>
#include <Scene.h>
#include <PhysicsManager.h>
#include "PlayerInputComponent.h"


bool Ogreman::PickUpComponent::InitComponent() {
	player_transform = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	my_player_input_comp = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<Ogreman::PlayerInputComponent>();
	return true;
}

void Ogreman::PickUpComponent::Update(const double& dt) {
	auto collided_list = VeryReal::PhysicsManager::Instance()->MakeRayCast(player_transform->GetPosition(), player_transform->GetPosition() + VeryReal::Vector3(1000,0,0));
	std::cout << "N colisionados: " << collided_list.size() << "\n";
	int cont = 0;
	for (auto elem_collided : collided_list) {
		if (elem_collided->HasComponent("NoteComponent") || elem_collided->HasComponent("CellComponent")) {
			my_player_input_comp->setCanPickUp(true);
			cont++;
		}
	}
	if (cont == 0) {
		my_player_input_comp->setCanPickUp(false);
	}
}

void Ogreman::PickUpComponent::GetElement() {
	std::cout << "COGER" << "\n";
	// Raycast
	// Detectar si es una nota o una pila 
	// LLamar al playerInteraction para hacer GetCell() o GetNote()
	// Borrar
}
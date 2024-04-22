#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "PlayerInteractionComponent.h"
#include <SceneManager.h>
#include <Scene.h>
#include <PhysicsManager.h>
#include "PlayerInputComponent.h"
#include "NoteComponent.h"
#include "CellComponent.h"
#include "CameraComponent.h"
#include <UI/UISpriteRenderComponent.h>
#include <UI/UItransformComponent.h>
#include <TransformComponent.h>
#include "RangosVisionComponent.h"
bool Ogreman::PickUpComponent::InitComponent() {
	player_transform = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	my_player_input_comp = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<Ogreman::PlayerInputComponent>();
	my_player_cam = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::CameraComponent>();
	return true;
}

void Ogreman::PickUpComponent::Update(const double& dt) {
	VeryReal::Vector4 orientation = my_player_cam->getOrientation();
	//std::cout << "Orientation: " << orientation.GetR() << " " << orientation.GetG() << " " << orientation.GetB() << " " << orientation.GetA() << "\n";
	//std::cout << "Player: " << player_transform->GetPosition().GetX() << " " << player_transform->GetPosition().GetY() << " " << player_transform->GetPosition().GetZ() << " " << "\n";
	//VeryReal::Vector3 h = player_transform->GetPosition() + VeryReal::Vector3(orientation.GetG(), orientation.GetB(), orientation.GetA()) * distance;
	//std::cout << "Ray: " << h.GetX() << " " << h.GetY() << " " << h.GetZ() << " " << "\n\n\n";
	auto collided_list = VeryReal::PhysicsManager::Instance()->MakeRayCast(player_transform->GetPosition(), player_transform->GetPosition() + VeryReal::Vector3(orientation.GetG(), orientation.GetB(), orientation.GetA()) * distance);
	std::cout << "N colisionados: " << collided_list.size() << "\n";
	int cont_notes = 0, cont_cells = 0;
	for (auto elem_collided : collided_list) {
		if (elem_collided->HasComponent("NoteComponent")) {
			my_player_input_comp->setCanPickUp(true);
			my_player_input_comp->setNoteToGet(elem_collided->GetComponent<NoteComponent>());
			settam(elem_collided);
			cont_notes++;
			control_update = true;
		}
		if (elem_collided->HasComponent("CellComponent")) {
			my_player_input_comp->setCanPickUp(true);
			my_player_input_comp->setCellToGet(elem_collided->GetComponent<CellComponent>());
			settam(elem_collided);
			cont_cells++;
			control_update = true;
		}
	}
	if (control_update) {
		if (cont_cells == 0 && cont_notes == 0) {
			my_player_input_comp->setCanPickUp(false);
		}
		else if (cont_cells == 0) {
			my_player_input_comp->setCellToGet(nullptr);
		}
		else if (cont_notes == 0) {
			my_player_input_comp->setNoteToGet(nullptr);
		}
		control_update = false;
	}
}
void Ogreman::PickUpComponent::settam(VeryReal::Entity* obj) {
	VeryReal::UITransformComponent* ui = obj->GetComponent<VeryReal::UITransformComponent>();
	VeryReal::UiSpriteRenderer* sp = obj->GetComponent<VeryReal::UiSpriteRenderer>();
	//rangos de vision lo tiene que tener el personaje
	Ogreman::RangosVisionComponent* rv = GetEntity()->GetComponent<Ogreman::RangosVisionComponent>();

	if (ui == nullptr || sp == nullptr || rv == nullptr) {
		//si no tiene esos dos componentes entonces se devuelve porque no hay cartel
		return;

	}
	//se activa la imagen
	
	VeryReal::TransformComponent* tmine = GetEntity()->GetComponent<VeryReal::TransformComponent>();
	VeryReal::TransformComponent* tobj = obj->GetComponent<VeryReal::TransformComponent>();

	//cogemos la distancia desde nuestra posicion hasta el objeto 
	float dist = tmine->GetPosition().Distance(tobj->GetPosition());
	float rangodistancia = rv->GetVisionDif();
	float aux = dist - rv->GetminVision();
	aux = aux / rangodistancia;
	//calculamos el valor con respecto al tamaño 
	float rangotamano = rv->GetTamDif();
	rangotamano = rangotamano * aux;
	rangotamano += rv->GetminTam();
	sp->setScale(VeryReal::Vector2(rangotamano, rangotamano));
	ui->SetActive(true);
}

void Ogreman::PickUpComponent::GetElement(NoteComponent* note, CellComponent* cell) {
	std::cout << "COGER" << "\n";
	if (note != nullptr) {
		my_player_interaction_comp->GetNote(note->getText());
		note->SetActive(false);
	}
	if (cell != nullptr) {
		my_player_interaction_comp->GetCell();
		cell->SetActive(false);
	}
	// Raycast
	// Detectar si es una nota o una pila 
	// LLamar al playerInteraction para hacer GetCell() o GetNote()
	// Borrar
}
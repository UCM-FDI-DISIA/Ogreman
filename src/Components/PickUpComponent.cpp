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
	player_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_player_input_comp = this->GetEntity()->GetComponent<Ogreman::PlayerInputComponent>();
	my_player_interaction_comp = this->GetEntity()->GetComponent<Ogreman::PlayerInteractionComponent>();
	my_player_cam = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();
	return true;
}

void Ogreman::PickUpComponent::Update(const double& dt) {
	//VeryReal::Vector4 orientation = my_player_cam->getOrientation();
	//std::cout << "Orientation: " << orientation.GetR() << " " << orientation.GetG() << " " << orientation.GetB() << " " << orientation.GetA() << "\n";
	//std::cout << "Player: " << player_transform->GetPosition().GetX() << " " << player_transform->GetPosition().GetY() << " " << player_transform->GetPosition().GetZ() << " " << "\n";
	//VeryReal::Vector3 h = player_transform->GetPosition() + VeryReal::Vector3(orientation.GetG(), orientation.GetB(), orientation.GetA()) * distance;
	//std::cout << "Ray: " << h.GetX() << " " << h.GetY() << " " << h.GetZ() << " " << "\n\n\n";
	VeryReal::Vector3 origin = player_transform->GetPosition();
	VeryReal::Vector3 d = player_transform->getFacingDirection();
	//VeryReal::Vector3 dest = { 20, 7, 70 };
	VeryReal::Vector3 dest = player_transform->GetPosition() + d * distance;

	auto collided_list = VeryReal::PhysicsManager::Instance()->MakeRayCast(origin, dest);
	
	int cont_notes = 0, cont_cells = 0;
	for (auto elem_collided : collided_list) {
		if (elem_collided->GetActive()) {
			if (elem_collided->HasComponent("NoteComponent")) {
				my_player_input_comp->setCanPickUp(true);
				my_player_input_comp->setNoteToGet(elem_collided->GetComponent<NoteComponent>());
				settam(elem_collided);
				cont_notes++;
				control_update_note = true;
			}
			if (elem_collided->HasComponent("CellComponent")) {
				my_player_input_comp->setCanPickUp(true);
				my_player_input_comp->setCellToGet(elem_collided->GetComponent<CellComponent>());
				settam(elem_collided);
				cont_cells++;
				control_update_cell = true;
			}
		}
		
	}
	if (control_update_cell || control_update_note) {
		std::cout << cont_cells << " n cells " << control_update_cell << std::endl;
		if (cont_cells == 0 && cont_notes == 0) {
			my_player_input_comp->setCanPickUp(false);
		}
		 if (cont_cells == 0 && control_update_cell ) {
			my_player_input_comp->getCellToGet()->GetComponent<VeryReal::UITransformComponent>()->hideElement();
			my_player_input_comp->setCellToGet(nullptr);
			control_update_cell = false;
		}
		 if (cont_notes == 0 && control_update_note ) {
			my_player_input_comp->getNoteToGet()->GetComponent<VeryReal::UITransformComponent>()->hideElement();

			my_player_input_comp->setNoteToGet(nullptr);
			control_update_note = false;
		}
		
	}

}
void Ogreman::PickUpComponent::settam(VeryReal::Entity* obj) {
	VeryReal::UITransformComponent* ui = obj->GetComponent<VeryReal::UITransformComponent>();
	VeryReal::UISpriteRendererComponent* sp = obj->GetComponent<VeryReal::UISpriteRendererComponent>();
	//rangos de vision lo tiene que tener el personaje
	Ogreman::RangosVisionComponent* rv = GetEntity()->GetComponent<Ogreman::RangosVisionComponent>();
//	ds->settodesactivate(true);
	if (ui == nullptr || sp == nullptr || rv == nullptr) {
		//si no tiene esos dos componentes entonces se devuelve porque no hay cartel
		return;

	}
	//se activa la imagen
	VeryReal::TransformComponent* tobj = obj->GetComponent<VeryReal::TransformComponent>();

	//cogemos la distancia desde nuestra posicion hasta el objeto 
	float dist = player_transform->GetPosition().Distance(tobj->GetPosition());
	float esc = 5.5f / dist;
	float ypos = 0.3 - esc;
	if (esc >= 0.2f) {
		esc = 0.2f;
	}
	if (esc <= 0.05f) {
		esc = 0.05f;
	}
	
	float d = esc;//esto es una mierda per por probar
	//calculamos el valor con respecto al tamaño 
	ui->setScale(VeryReal::Vector2(esc, esc));
	float xpos = 0.5 - (d/2);

	
	ui->setPosition(VeryReal::Vector2(xpos, ypos));
	ui->showElement();
}

void Ogreman::PickUpComponent::GetElement(NoteComponent* note, CellComponent* cell) {
	std::cout << "COGER" << "\n";
	if (note != nullptr) {
		my_player_interaction_comp->GetNote(note->getText());
		my_player_input_comp->setNoteToGet(nullptr);
		note->SetActive(false);
		note->GetEntity()->SetActive(false);
		control_update_note = false;
	}
	if (cell != nullptr) {
		my_player_interaction_comp->GetCell();
		my_player_input_comp->setCellToGet(nullptr);
		cell->SetActive(false);
		cell->GetEntity()->SetActive(false);
		control_update_cell = false;
	}
	// Raycast
	// Detectar si es una nota o una pila 
	// LLamar al playerInteraction para hacer GetCell() o GetNote()
	// Borrar
}
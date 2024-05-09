#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include "PlayerInteractionComponent.h"
#include <SceneManager.h>
#include <Scene.h>
#include "Entity.h"
#include <PhysicsManager.h>
#include "PlayerInputComponent.h"
#include "NoteComponent.h"
#include "CellComponent.h"
#include <UI/UISpriteRenderComponent.h>
#include <UI/UItransformComponent.h>
#include <TransformComponent.h>
#include "ShowImageComponent.h"
#include "RangosVisionComponent.h"
#include "NNotesComponent.h"

std::pair<bool, std::string> Ogreman::PickUpComponent::InitComponent() {
	player_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (player_transform == nullptr) {

		return { false, "TransformComponent isn't in this entity, ERROR from PickUpComponent" };
	}
	my_player_input_comp = this->GetEntity()->GetComponent<Ogreman::PlayerInputComponent>();
	if (my_player_input_comp == nullptr) {
		return{ false, "Player doesn't have PlayerInputComponent, ERROR from PickUpComponent" };
	}
	my_player_interaction_comp = this->GetEntity()->GetComponent<Ogreman::PlayerInteractionComponent>();
	if (my_player_interaction_comp == nullptr) {
		return{ false, "Player doesn't have PlayerInteractionComponent, ERROR from PickUpComponent" };
	}
	VeryReal::Entity* noteUI = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("NoteUI");
	if(noteUI != nullptr) 
		my_notes = noteUI->GetComponent<NNotesComponent>();

	if (my_notes == nullptr) {
		return{ false, "Player doesn't have NNotesComponent, ERROR from PickUpComponent" };
	}
	return { true, "" };
}

void Ogreman::PickUpComponent::Update(const double& dt) {

	VeryReal::Vector3 origin = player_transform->GetPosition();
	VeryReal::Vector3 d = player_transform->getFacingDirection();
	VeryReal::Vector3 dest = player_transform->GetPosition() + d * distance;

	auto collided_list = VeryReal::PhysicsManager::Instance()->MakeRayCast(origin, dest);
	
	int cont_notes = 0, cont_cells = 0;
	
	if (!collided_list.empty()) {
		auto elem_collided = collided_list.top();
		if (elem_collided.ent->GetActive()) {
			if (elem_collided.ent->HasComponent("NoteComponent")) {
				my_player_input_comp->setCanPickUp(true);
				my_player_input_comp->setNoteToGet(elem_collided.ent->GetComponent<NoteComponent>());
				settam(elem_collided.ent);
				cont_notes++;
				control_update_note = true;
			}
			if (elem_collided.ent->HasComponent("CellComponent")) {
				my_player_input_comp->setCanPickUp(true);
				my_player_input_comp->setCellToGet(elem_collided.ent->GetComponent<CellComponent>());
				settam(elem_collided.ent);
				cont_cells++;
				control_update_cell = true;
			}
		}

	}

	if (control_update_cell || control_update_note) {
	
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
	//calculamos el valor con respecto al tama�o 
	ui->setScale(VeryReal::Vector2(esc, esc));
	float xpos = 0.5 - (d/2);

	
	ui->setPosition(VeryReal::Vector2(xpos, ypos));
	ui->showElement();
}

void Ogreman::PickUpComponent::GetElement(NoteComponent* note, CellComponent* cell) {
	if (note != nullptr) {
		my_player_input_comp->setNoteToGet(nullptr);
		note->SetActive(false);
		std::string name = note->getText();
		ShowImageComponent* s = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity(name)->GetComponent<ShowImageComponent>();
		if (s != nullptr) {
			s->activeTime();
		}
		note->GetEntity()->SetActive(false);
		control_update_note = false;
		my_notes->RestaNota();
		note->PlayPickUpSound();
	}
	if (cell != nullptr) {
		my_player_interaction_comp->GetCell();
		my_player_input_comp->setCellToGet(nullptr);
		cell->SetActive(false);
		cell->GetEntity()->SetActive(false);
		control_update_cell = false;
		cell->PlayPickUpSound();
	}
}
#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioManager.h"
#include "PickUpComponent.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"
#include "NoteComponent.h"
#include "CellComponent.h"
#include "PhysicsManager.h"
using namespace std;

std::pair<bool, std::string> Ogreman::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (my_transform == nullptr) {
		return { false, "TransformComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	my_movement_component = this->GetEntity()->GetComponent<Ogreman::MovementComponent>();
	if (my_movement_component == nullptr) {
		return { false, "MovementComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();
	if (my_camera_component == nullptr) {
		return { false, "CameraComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	my_rigidbody = this->GetEntity()->GetComponent<VeryReal::RigidBodyComponent>();
	if (my_rigidbody == nullptr) {
		return { false, "RigidBodyComponent isn't in this entity, ERROR from PlayerInputComponent" };
	}
	
	return { true," " };
}
VeryReal::Entity* Ogreman::PlayerInputComponent::getCellToGet() {
	return cell_to_get->GetEntity();
}
VeryReal::Entity* Ogreman::PlayerInputComponent::getNoteToGet() {
	return note_to_get->GetEntity();

}
void Ogreman::PlayerInputComponent::Update(const double& dt) {
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) { // Movimiento Teclado
		float sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}
		VeryReal::Vector3 forwardDirection = my_transform->getFacingDirection();
		VeryReal::Vector3 rightDirection = forwardDirection.Cross(VeryReal::Vector3(0, 1, 0)).Normalize();

		float moveX = 0.0f;
		float moveZ = 0.0f;

		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			moveX += forwardDirection.GetX();
			moveZ += forwardDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			moveX -= forwardDirection.GetX();
			moveZ -= forwardDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			moveX -= rightDirection.GetX();
			moveZ -= rightDirection.GetZ();
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			moveX += rightDirection.GetX();
			moveZ += rightDirection.GetZ();
		}

		my_movement_component->SetMoventDirectionX(moveX * sprint);
		my_movement_component->SetMoventDirectionZ(moveZ * sprint);

		if (canPickUp) { 
			if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_E)) {
				this->GetEntity()->GetComponent<Ogreman::PickUpComponent>()->GetElement(note_to_get, cell_to_get);
			}
		}

		//Camara con teclado y raton 
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LEFT)) { // Rotar la cámara hacia la izquierda
			my_camera_component->yaw(1);
			my_rigidbody->Rotate(VeryReal::Vector3(0, 1, 0), -1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_RIGHT)) { // Rotar la cámara hacia la derecha
			my_camera_component->yaw(-1);
			my_rigidbody->Rotate(VeryReal::Vector3(0, 1, 0), 1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_UP)) { // Rotar la cámara hacia arriba
			my_camera_component->rotate(1, rightDirection);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_DOWN)) { // Rotar la cámara hacia abajo
			my_camera_component->rotate(-1, rightDirection);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_ESCAPE)) {
			//VeryReal::InputManager::Instance()->Quit();
		}
	}
	else {
		float sprint = 2;
		// Movimiento Mando
		my_movement_component->SetMoventDirectionX(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(sprint * VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));

		// Camara Mando
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) != 0) {
			my_camera_component->yaw(-VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX));
		}
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) != 0) {
			my_camera_component->pitch(-VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY));
		}
	}
	if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_Y)) {
		VeryReal::PhysicsManager::Instance()->SeeDebugColliders(true);
	}
	// Linterna
	if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LCTRL) ||
		VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_TRIGGERRIGHT) > 0) {
		flashlight = true;
	}
	else {
		flashlight = false;
	}
	// AUDIO

	audio_intensity = VeryReal::AudioManager::Instance()->InputSoundIntensity();
}
bool Ogreman::PlayerInputComponent::IsFlashLightPressed() {
	return flashlight; 
}
void Ogreman::PlayerInputComponent::setCanPickUp(bool newValue) {
	canPickUp = newValue;
}

void Ogreman::PlayerInputComponent::setCellToGet(CellComponent* newCell) {
	cell_to_get = newCell;
}

void Ogreman::PlayerInputComponent::setNoteToGet(NoteComponent* newNote) {
	note_to_get = newNote;
}
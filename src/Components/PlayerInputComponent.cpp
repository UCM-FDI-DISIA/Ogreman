#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioLeon.h"
#include "PickUpComponent.h"
#include "TransformComponent.h"

using namespace std;

bool Ogreman::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<Ogreman::MovementComponent>();
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();

	if (this->my_movement_component != nullptr && this->my_camera_component != nullptr)
		return true;
	else
		return false;
}

void Ogreman::PlayerInputComponent::Update(const double& dt){
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

		cout << moveX << " " << moveZ << endl;

		my_movement_component->SetMoventDirectionX(moveX * sprint);
		my_movement_component->SetMoventDirectionZ(moveZ * sprint);

		if (canPickUp) { // Anadir UI de PULSA E
			if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_E)) {
				my_pickup_component->GetElement(note_to_get, cell_to_get);
			}
		}

		//Camara con teclado y raton 
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LEFT)) { // Rotar la cámara hacia la izquierda
			my_camera_component->yaw(1);
			my_transform->Rotate(VeryReal::Vector3(0, -1, 0));
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_RIGHT)) { // Rotar la cámara hacia la derecha
			my_camera_component->yaw(-1);
			my_transform->Rotate(VeryReal::Vector3(0, 1, 0));
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

	// Linterna
	if (VeryReal::InputManager::Instance()->GetMouseButtonState(TI_MOUSE_LEFT) ||
		VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_TRIGGERRIGHT) > 0) {
		flashlight = true;
	}
	else {
		flashlight = false;
	}

	// AUDIO
	audio_intensity = VeryReal::AudioLeon::Instance()->InputSoundIntensity();
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
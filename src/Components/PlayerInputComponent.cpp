#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioLeon.h"
#include "PickUpComponent.h"
#include "TransformComponent.h"

bool Ogreman::PlayerInputComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_movement_component = this->GetEntity()->GetComponent<Ogreman::MovementComponent>();
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>();

	if (this->my_movement_component != nullptr && this->my_camera_component != nullptr)
		return true;
	else
		return false;
}

VeryReal::Vector3 Ogreman::PlayerInputComponent::getFacingDirection(const VeryReal::Vector3& rotation) {
	float radX = rotation.GetX() * 3.14159f / 180.0f;
	float radY = rotation.GetY() * 3.14159f / 180.0f;
	float radZ = rotation.GetZ() * 3.14159f / 180.0f;

	// Definir la direcci�n por defecto
	VeryReal::Vector3 defaultDirection(0, 0, -1);

	// Aplicar rotaciones en orden Z, X, Y
	VeryReal::Vector3 facingDirection(
		defaultDirection.GetX() * (cos(radY) * cos(radZ)) + defaultDirection.GetX() * (cos(radY) * sin(radZ)) + defaultDirection.GetZ() * (-sin(radY)),
		defaultDirection.GetY() * (sin(radX) * sin(radY) * cos(radZ) - cos(radX) * sin(radZ)) + defaultDirection.GetY() * (sin(radX) * sin(radY) * sin(radZ) + cos(radX) * cos(radZ)) + defaultDirection.GetZ() * (sin(radX) * cos(radY)),
		defaultDirection.GetZ() * (cos(radX) * sin(radY) * cos(radZ) + sin(radX) * sin(radZ)) + defaultDirection.GetY() * (cos(radX) * sin(radY) * sin(radZ) - sin(radX) * cos(radZ)) + defaultDirection.GetZ() * (cos(radX) * cos(radY))
	);

	return facingDirection.Normalize();
}

void Ogreman::PlayerInputComponent::Update(const double& dt){
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) {
		// Movimiento Teclado
		float sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 2;
		}
		/*if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			my_movement_component->SetMoventDirectionX(-sprint);
		}
		else if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			my_movement_component->SetMoventDirectionX(sprint);
		}
		else {
			my_movement_component->SetMoventDirectionX(0);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			my_movement_component->SetMoventDirectionZ(sprint);
		}
		else if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			my_movement_component->SetMoventDirectionZ(-sprint);
		}
		else {
			my_movement_component->SetMoventDirectionZ(0);
		}*/

		VeryReal::Vector3 forwardDirection = getFacingDirection(my_transform->GetRotation()).Normalize();
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

		my_movement_component->SetMoventDirectionX(moveX);
		my_movement_component->SetMoventDirectionZ(moveZ);

		if (canPickUp) { // Anadir UI de PULSA E
			if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_E)) {
				my_pickup_component->GetElement(note_to_get, cell_to_get);
			}
		}

		//Camara con teclado y raton 
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LEFT)) {
			my_transform->Rotate(VeryReal::Vector3(0, -1, 0));
			my_camera_component->yaw(1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_RIGHT)) {
			my_transform->Rotate(VeryReal::Vector3(0, 1, 0));
			my_camera_component->yaw(-1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_UP)) {
			my_camera_component->pitch(1);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_DOWN)) {
			my_camera_component->pitch(-1);
		}
	
		/*std::pair<int32_t, int32_t> mouse_pos = VeryReal::InputManager::Instance()->GetMousePos();

		double yaw = (mouse_pos.first - prev_mouse_pos.first) * sensitivity;
		double roll = (mouse_pos.second - prev_mouse_pos.second) * sensitivity;
		my_camera_component->yaw(yaw);
		my_camera_component->roll(roll);


		prev_mouse_pos = mouse_pos;*/
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_ESCAPE)) 
		{
			//VeryReal::InputManager::Instance()->Quit();
		}
	}
	else {
		// Movimiento Mando
		my_movement_component->SetMoventDirectionX(VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));
	
		// Camara Mando
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) != 0) {
			my_camera_component->yaw(VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX));
		}
		if (VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) != 0) {
			my_camera_component->pitch(VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY));
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

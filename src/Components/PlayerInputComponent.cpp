#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioLeon.h"

void VeryReal::PlayerInputComponent::InitComponent() {
	my_movement_component = this->GetEntity()->GetComponent<MovementComponent>("MovementComponent");
	my_camera_component = this->GetEntity()->GetComponent<CameraComponent>("CameraComponent");
}

void VeryReal::PlayerInputComponent::Update(const double& dt){
	// Movimiento Mando
	if (InputManager::Instance()->IsGameControllerConnected()) {
		int sprint = 0.5;
		if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}
		if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			my_movement_component->SetMoventDirectionX(-sprint);
		}
		else if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			my_movement_component->SetMoventDirectionX(sprint);
		}
		if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			my_movement_component->SetMoventDirectionZ(sprint);
		}
		else if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			my_movement_component->SetMoventDirectionZ(-sprint);
		}
	}
	// Movimiento Teclado
	else {
		my_movement_component->SetMoventDirectionX(InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX));
		my_movement_component->SetMoventDirectionZ(InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY));
	}
	

	// Camara
	if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) != 0) {
		my_camera_component->yaw(InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX));
	}
	if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) != 0){
		my_camera_component->roll(InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY));
	}

	// Linterna
	if (InputManager::Instance()->GetMouseButtonState(TI_MOUSE_LEFT)) {
		flashlight = true;
	}
	else {
		flashlight = false;
	}

	// AUDIO
	audio_intensity = Audio_Leon::InputSoundIntensity();
}

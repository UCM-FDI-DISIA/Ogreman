#include "PlayerInputComponent.h"
#include "MovementComponent.h"
#include "Entity.h"
#include "Manager.h"
#include "InputManager.h"
#include "CameraComponent.h"
#include "AudioLeon.h"

bool Ogreman::PlayerInputComponent::InitComponent() {
	my_movement_component = this->GetEntity()->GetComponent<Ogreman::MovementComponent>("MovementComponent");
	my_camera_component = this->GetEntity()->GetComponent<VeryReal::CameraComponent>("CameraComponent");

	if (this->my_movement_component != nullptr && this->my_camera_component != nullptr)
		return true;
	else
		return false;
}

void Ogreman::PlayerInputComponent::Update(const double& dt){
	if (!VeryReal::InputManager::Instance()->IsGameControllerConnected()) {
		// Movimiento Teclado
		int sprint = 0.5;
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_LSHIFT)) {
			sprint = 1;
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_A)) {
			my_movement_component->SetMoventDirectionX(-sprint);
		}
		else if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_D)) {
			my_movement_component->SetMoventDirectionX(sprint);
		}
		if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_W)) {
			my_movement_component->SetMoventDirectionZ(sprint);
		}
		else if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_S)) {
			my_movement_component->SetMoventDirectionZ(-sprint);
		}

		// Camara con teclado y raton 
		std::pair<int32_t, int32_t> mouse_pos = VeryReal::InputManager::Instance()->GetMousePos();

		double yaw = (mouse_pos.first - prev_mouse_pos.first) * sensitivity;
		double roll = (mouse_pos.second - prev_mouse_pos.second) * sensitivity;
		my_camera_component->yaw(yaw);
		my_camera_component->roll(roll);

		prev_mouse_pos = mouse_pos;
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
			my_camera_component->roll(VeryReal::InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY));
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

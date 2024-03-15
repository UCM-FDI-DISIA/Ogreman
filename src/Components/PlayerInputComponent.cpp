//#include "PlayerInputComponent.h"
//#include "MovementComponent.h"
//#include "GuilleElArquitecto/Entity.h"
//#include "GuilleElArquitecto/Manager.h"
//#include "TonInput/InputManager.h"
//
//void VeryReal::PlayerInputComponent::InitComponent() {
//	my_movement_component = this->GetEntity()->GetComponent<MovementComponent>("MovementComponent");
//}
//
//
//void VeryReal::PlayerInputComponent::Update(const double& dt){
//	// Movimiento
//	if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_A) || InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX) < 0) {
//		my_movement_component->SetMoventDirectionX(-1);
//	}
//	else if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_D) || InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTX) > 0) {
//		my_movement_component->SetMoventDirectionX(1);
//	}
//	if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_W) || InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY) < 0) {
//		my_movement_component->SetMoventDirectionZ(1);
//	}
//	else if (InputManager::Instance()->IsKeyDown(TI_SCANCODE_S) || InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_LEFTY) > 0) {
//		my_movement_component->SetMoventDirectionZ(-1);
//	}
//
//	// Camara
//	if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) < 0) {
//		
//	}
//	else if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTX) > 0) {
//		
//	}
//	if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) < 0) {
//		
//	}
//	else if (InputManager::Instance()->GetJoystickAxisState(TI_CONTROLLER_AXIS_RIGHTY) > 0) {
//		
//	}
//
//	// Linterna
//	if (InputManager::Instance()->GetMouseButtonState(TI_MOUSE_LEFT)) {
//		flashlight = true;
//	}
//	else {
//		flashlight = false;
//	}
//
//	// AUDIO
//}
//

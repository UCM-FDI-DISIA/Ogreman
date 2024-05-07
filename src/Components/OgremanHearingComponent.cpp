#include "OgremanHearingComponent.h"
#include "OgremanControllerComponent.h"
#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "PlayerInputComponent.h"
#include "TransformComponent.h"
#include "InputManager.h"
#include "Entity.h"
#include <SceneManager.h>
#include <AudioManager.h>
#include <Vector3.h>
#include <Scene.h>
#include <cmath> 
#include <math.h>

std::pair<bool, std::string> Ogreman::OgremanHearingComponent::InitComponent(float rate, int sensitivity, float lowerThreshold, float upperThreshold)
{
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	my_controller = this->GetEntity()->GetComponent<OgremanControllerComponent>();
	player_transform = VeryReal::SceneManager::Instance()->GetScene("HouseScene")->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	player_input = VeryReal::SceneManager::Instance()->GetScene("HouseScene")->GetEntity("Player")->GetComponent<PlayerInputComponent>();
	radius_growth_rate = rate;
	ogre_sound_sensitivity = sensitivity;
	lower_intensity_threshold = lowerThreshold;
	upper_intensity_threshold = upperThreshold;
	player_noise_intensity = 0;
	if(my_transform != nullptr ){
		return { true, "" };
	}
	else {
		return { false, " " };
	}
}

void Ogreman::OgremanHearingComponent::Update(const double& dt)
{
	player_noise_intensity = VeryReal::AM().InputSoundIntensity();
	/*if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_I)) {
		player_noise_intensity += 0.001;

		std::cout << "Suma" << std::endl;
	}
	if (VeryReal::InputManager::Instance()->IsKeyDown(TI_SCANCODE_U)) {
		player_noise_intensity -= 0.001;
		std::cout << "Resta" << std::endl;
	}*/
	if (player_noise_intensity < lower_intensity_threshold) player_noise_intensity = 0;
	else if(player_noise_intensity >= upper_intensity_threshold) player_noise_intensity = upper_intensity_threshold;
	//std::cout << player_noise_intensity << std::endl;
	hearing_radius = CalculateRadius(player_noise_intensity);
#ifdef _DEBUG
	/*std::cout << "hearing_radius" << hearing_radius << "... \n";*/
#endif
	float dist_ogre_player = (my_transform->GetPosition().Distance(player_transform->GetPosition())) / 10;
	if (hearing_radius >= dist_ogre_player) {
		VeryReal::Vector3 player_position = player_transform->GetPosition();
		my_controller->GoToLocation(player_position);
		//std::cout << "detectado" << std::endl;
		player_detected = true;
	}
	else {
		player_detected = false;
	}

}

float Ogreman::OgremanHearingComponent::CalculateRadius(float intensity)
{	float radio = ogre_sound_sensitivity * (exp(radius_growth_rate * intensity) - 1) / (exp(radius_growth_rate) - 1);
	return radio;
}

bool Ogreman::OgremanHearingComponent::GetDetected()
{
	return player_detected;
}

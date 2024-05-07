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
	if (my_transform == nullptr) {

		return { false, "TransformComponent isn't in this entity, ERROR from OgremanHearingComponent" };
	}
	my_controller = this->GetEntity()->GetComponent<OgremanControllerComponent>();
	if (my_controller == nullptr) {

		return { false, "OgremanControllerComponent isn't in this entity, ERROR from OgremanHearingComponent" };
	}
	VeryReal::Entity* player = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player");
	if (player == nullptr) {
		return{ false, "The Player doesn't exist, ERROR from OgremanHearingComponent" };
	}
	player_transform = player->GetComponent<VeryReal::TransformComponent>();
	if (player_transform == nullptr) {
		return{ false, "Player doesn't have Transform, ERROR from OgremanHearingComponent" };
	}
	player_input = player->GetComponent<PlayerInputComponent>();
	if (player_input == nullptr) {
		return{ false, "Player doesn't have PlayerInputComponent, ERROR from OgremanHearingComponent" };
	}
	radius_growth_rate = rate;
	ogre_sound_sensitivity = sensitivity;
	lower_intensity_threshold = lowerThreshold;
	upper_intensity_threshold = upperThreshold;
	player_noise_intensity = 0;
	return { true,"OgremanHearingComponent was made correct" };
}

void Ogreman::OgremanHearingComponent::Update(const double& dt)
{
	player_noise_intensity = VeryReal::AM().InputSoundIntensity();
	if (player_noise_intensity < lower_intensity_threshold) player_noise_intensity = 0;
	else if(player_noise_intensity >= upper_intensity_threshold) player_noise_intensity = upper_intensity_threshold;
	hearing_radius = CalculateRadius(player_noise_intensity);
	float dist_ogre_player = (my_transform->GetPosition().Distance(player_transform->GetPosition())) / 10;
	if (hearing_radius >= dist_ogre_player) {
		VeryReal::Vector3 player_position = player_transform->GetPosition();
		my_controller->GoToLocation(player_position);
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

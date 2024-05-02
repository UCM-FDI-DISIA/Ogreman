#include "OgremanHearingComponent.h"
#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "PlayerInputComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <AudioManager.h>
#include <Vector3.h>
#include <Scene.h>
#include <cmath> 
#include <math.h>

bool Ogreman::OgremanHearingComponent::InitComponent()
{
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	player_transform = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	player_input = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<PlayerInputComponent>();
	radius_growth_rate = 3;
	ogre_sound_sensitivity = 5;
	if(my_transform != nullptr ){
		return true;
	}
	else {
		return false;
	}
}

void Ogreman::OgremanHearingComponent::Update(const double& dt)
{
	player_noise_intensity = VeryReal::AM().InputSoundIntensity();
	hearing_radius = CalculateRadius(player_noise_intensity);
#ifdef _DEBUG
	std::cout << "hearing_radius" << hearing_radius << "... \n";
#endif
	float dist_ogre_player = my_transform->GetPosition().Distance(player_transform->GetPosition());
	if (hearing_radius >= dist_ogre_player) {
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

#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
#include "UI/UITransformComponent.h"
#include "GameManager.h"
#include "ShowImageComponent.h"
#include "AudioSourceComponent.h"
#include "Entity.h"
#include "ErrorManager.h"
std::pair<bool, std::string>  Ogreman::OgremanAttackComponent::InitComponent() {

	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (my_transform == nullptr) {
		return{ false, "Transform Component isn't in this entity, ERROR from OgremanAttackComponent" };
	}

	VeryReal::Entity* player = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player");
	if (player == nullptr) {
		return{ false, "The Player doesn't exist, ERROR from OgreMan AttackComponent" };
	}

	VeryReal::Entity* screamer = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Screamer");
	if (screamer == nullptr) {
		return{ false, "The Screamer doesn't exist, ERROR from OgreMan AttackComponent" };
	}
	
	player_transform = player->GetComponent<VeryReal::TransformComponent>();
	if (player_transform == nullptr) {
		return{ false, "Player doesn't have Transform, ERROR from OgreMan AttackComponent" };
	}

	player_UI = player->GetComponent<VeryReal::UITransformComponent>();
	if (player_UI == nullptr) {
		return{ false, "Player doesn't have UITransform, ERROR from OgreMan AttackComponent" };
	}
	screamer_image = screamer->GetComponent<Ogreman::ShowImageComponent>();
	if (screamer_image == nullptr) {
		return{ false, "Screamer doesn't have ShowImageComponent, ERROR from OgreMan AttackComponent" };
	}
	audio_detected = screamer->GetComponent<VeryReal::AudioSourceComponent>();
	if (audio_detected == nullptr) {
		return{ false, "Screamer doesn't have ShowImageComponent, ERROR from OgreMan AttackComponent" };
	}
	delay_scream = screamer_image->getTimeToShow();

	return { true, "OgreManAttackComponent Correct Init" };
}

void  Ogreman::OgremanAttackComponent::Update(const double& dt)
{
	if (!attacking) {
		if (my_transform->GetPosition().Distance(player_transform->GetPosition()) < range)
		{
			if (nAttacks < maxAttacks) {
				attacking = true;
				player_UI->hideElement();
				screamer_image->activeTime();
				VeryReal::ErrorManager::Instance()->canBeError(audio_detected->Play());
				nAttacks++;
			}
			else {
				GameManager::Instance()->Lose();
			}
		}
	}
	else {
		if (delay > delay_scream) 
		{
			delay = 0;
			attacking = false;
			player_UI->showElement();
		}
		else {
			delay += (float) dt;
		}
	}
}

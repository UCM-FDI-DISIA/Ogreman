#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
#include "UI/UITransformComponent.h"
#include "GameManager.h"
#include "ShowImageComponent.h"
#include "AudioSourceComponent.h"
bool Ogreman::OgremanAttackComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	player_transform = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	player_UI = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Player")->GetComponent<VeryReal::UITransformComponent>();
	screamer_image = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Screamer")->GetComponent<Ogreman::ShowImageComponent>();
	audio_detected = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("Screamer")->GetComponent<AudioSourceComponent>();
	delay_scream = screamer_image->getTimeToShow();
	if (this->my_transform != nullptr)
		return true;
	else
		return false;
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
				audio_detected->Play();
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

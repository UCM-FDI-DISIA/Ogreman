#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
#include "UI/UISpriteRenderComponent.h"
#include "UI/UITransformComponent.h"
#include "GameManager.h"
bool Ogreman::OgremanAttackComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	player_transform = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::TransformComponent>();
	player_UI = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::UITransformComponent>();
	sprite_renderer_player = VeryReal::SceneManager::Instance()->GetScene("Play")->GetEntity("Player")->GetComponent<VeryReal::UISpriteRendererComponent>();
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
				player_UI->showElement();
				nAttacks++;
			}
			else {
				GameManager::Instance()->Loose();
			}
		}
	}
	else {
		if (delay > delay_scream) {
			player_UI->hideElement();
			delay = 0;
			attacking = false;
		}
		else {
			delay += (float) dt;
		}
	}
}

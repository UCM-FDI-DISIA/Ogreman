#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
bool Ogreman::OgremanAttackComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	player_transform = VeryReal::SceneManager::Instance()->GetScene("a")->GetEntity("player")->GetComponent<VeryReal::TransformComponent>();
	if (this->my_transform != nullptr)
		return true;
	else
		return false;
}

void  Ogreman::OgremanAttackComponent::Update(const double& dt)
{
	if(my_transform->GetPosition().Magnitude() - player_transform->GetPosition().Magnitude() < 10)
	{
		std::cout << "SUSTO";
	}
}

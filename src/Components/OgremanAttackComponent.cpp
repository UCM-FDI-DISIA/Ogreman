#include "OgremanAttackComponent.h"
#include "TransformComponent.h"
#include "Entity.h"
#include <SceneManager.h>
#include <Scene.h>
bool VeryReal::OgremanAttackComponent::InitComponent() {
	my_transform = this->GetEntity()->GetComponent<TransformComponent>("TransformComponent");
	player_transform = SceneManager::Instance()->GetScene("a")->GetEntity("player")->GetComponent<TransformComponent>("TransformComponent");
	if (this->my_transform != nullptr)
		return true;
	else
		return false;
}

void VeryReal::OgremanAttackComponent::Update(const double& dt) 
{
	if(my_transform->GetPosition().Magnitude() - player_transform->GetPosition().Magnitude() < 10)
	{
		std::cout << "SUSTO";
	}
}

#include "TransformFollowComponent.h"
#include "TransformComponent.h"
#include "InputManager.h"
#include "Entity.h"
#include <SceneManager.h>
#include <AudioManager.h>
#include <Vector3.h>
#include <Scene.h>
#include <cmath> 
#include <math.h>

std::pair<bool, std::string> Ogreman::TransformFollowComponent::InitComponent(std::string targetEntityName)
{
	my_transform = this->GetEntity()->GetComponent<VeryReal::TransformComponent>();
	if (my_transform == nullptr) {
		return { false, "TransformComponent isn't in this entity, ERROR from OgremanHearingComponent" };
	}
	VeryReal::Entity* target = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity(targetEntityName);
	if (target == nullptr) {
		return{ false, "The entity " + targetEntityName + " doesn't exist, ERROR from TransformFollowComponent" };
	}
	target_transform = target->GetComponent<VeryReal::TransformComponent>();
	if (target_transform == nullptr) {
		return{ false, targetEntityName + " doesn't have Transform, ERROR from OgremanHearingComponent" };
	}

	return { true,"TransformFollowComponent was made correct" };
}

void Ogreman::TransformFollowComponent::Update(const double& dt)
{
	my_transform->SetPosition(target_transform->GetPosition());
}

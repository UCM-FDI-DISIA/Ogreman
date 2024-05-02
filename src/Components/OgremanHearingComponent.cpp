#include "OgremanHearingComponent.h"
#include "PlayerInputComponent.h"
#include "TransformComponent.h"
#include <cmath> 
#include <math.h>

bool Ogreman::OgremanHearingComponent::InitComponent()
{
	return false;
}

void Ogreman::OgremanHearingComponent::Update(const double& dt)
{
}

float Ogreman::OgremanHearingComponent::CalculateRadius(float intensity)
{
	return 0.0f;
}

bool Ogreman::OgremanHearingComponent::GetDetected()
{
	return player_detected;
}

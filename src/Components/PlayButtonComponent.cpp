#include "PlayButtonComponent.h"
#include "GameManager.h"

void Ogreman::PlayButtonComponent::Action()
{
	Ogreman::GameManager::Instance()->Play();		
}

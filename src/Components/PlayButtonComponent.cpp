#include "PlayButtonComponent.h"
#include "GameManager.h"

void Ogreman::PlayButtonComponent::accion()
{
	Ogreman::GameManager::Instance()->Play();		
}

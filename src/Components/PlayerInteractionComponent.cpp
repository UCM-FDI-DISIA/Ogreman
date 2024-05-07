#include "PlayerInteractionComponent.h"
#include "FlashlightComponent.h"
#include "NoteComponent.h"
#include "Entity.h"

std::pair<bool, std::string>  Ogreman::PlayerInteractionComponent::InitComponent() {
	return { true, " " };
}

void Ogreman::PlayerInteractionComponent::GetCell()
{
	this->GetEntity()->GetComponent<Ogreman::FlashlightComponent>()->ChargeBatery(10); //la cantidad es temporal
}

void Ogreman::PlayerInteractionComponent::GetNote(std::string note)
{
	/*string myText = */
	//hacer aparecer el texto en pantalla
}

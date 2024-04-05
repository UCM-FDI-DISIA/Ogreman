#include "PlayerInteractionComponent.h"
#include "FlashlightComponent.h"
#include "NoteComponent.h"

bool Ogreman::PlayerInteractionComponent::InitComponent() {
	/*my_flashlight_component = this->GetEntity()->GetComponent<Ogreman::FlashlightComponent>("FlashlightComponent");*/
	return true;
}

void Ogreman::PlayerInteractionComponent::GetCell()
{
	my_flashlight_component->ChargeBatery(10); //la cantidad es temporal
}

void Ogreman::PlayerInteractionComponent::GetNote(std::string note)
{
	/*string myText = */
	//hacer aparecer el texto en pantalla
}

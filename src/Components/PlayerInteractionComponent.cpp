#include "PlayerInteractionComponent.h"
#include "FlashlightComponent.h"
#include "NoteComponent.h"

bool VeryReal::PlayerInteractionComponent::InitComponent() {
	/*my_flashlight_component = this->GetEntity()->GetComponent<Ogreman::FlashlightComponent>("FlashlightComponent");*/
	return true;
}

void VeryReal::PlayerInteractionComponent::GetCell()
{
	my_flashlight_component->ChargeBatery(10); //la cantidad es temporal
}

void VeryReal::PlayerInteractionComponent::GetNote(NoteComponent* note)
{
	/*string myText = */
	//hacer aparecer el texto en pantalla
}

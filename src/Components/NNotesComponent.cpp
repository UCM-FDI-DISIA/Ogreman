#include "NNotesComponent.h"
#include "Entity.h"
#include "UI/UITextComponent.h"
#include "string"
std::pair<bool, std::string>  Ogreman::NNotesComponent::InitComponent(int notes, int totalnotas) {
	numnotes = notes;
	this->totalnotas = totalnotas;
	return { true," " };
}

	
void Ogreman::NNotesComponent::restanota() {
	numnotes--;
	this->GetEntity()->GetComponent<VeryReal::UITextComponent>()->setCaption(std::to_string(numnotes));
}
int Ogreman::NNotesComponent::getnnota() {
	return numnotes;
}
int Ogreman::NNotesComponent::getotalnotas() {
	return totalnotas;
}
bool Ogreman::NNotesComponent::totalnotes() {
	return numnotes == totalnotas;
}
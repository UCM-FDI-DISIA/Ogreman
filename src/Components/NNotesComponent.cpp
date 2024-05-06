#include "NNotesComponent.h"
bool Ogreman::NNotesComponent::InitComponent(int notes, int totalnotas) {
	numnotes = notes;
	this->totalnotas = totalnotas;
	return true;
}

	
void Ogreman::NNotesComponent::restanota() {
	numnotes--;
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
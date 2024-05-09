#include "NNotesComponent.h"
#include "Entity.h"
#include "UI/UITextComponent.h"
#include "string"
#include "GameManager.h"

std::pair<bool, std::string>  Ogreman::NNotesComponent::InitComponent(int notes, int totalnotas) {
	numnotes = notes;
	this->totalnotas = totalnotas;

	texto = this->GetEntity()->GetComponent<VeryReal::UITextComponent>();
	if(texto == nullptr)
		return { false,"NNotesComponent was NOT made right-->InitComponent" };
	texto->setCaption(std::to_string(numnotes)); 

	return { true,"NNotesComponent was made right-->InitComponent" };
}

void Ogreman::NNotesComponent::RestaNota() {
	numnotes--;
	texto->setCaption(std::to_string(numnotes));

	if (numnotes <= 3) {
		GameManager::Instance()->NextLevel();
	}
}

int Ogreman::NNotesComponent::GetNNota() {
	return numnotes;
}

int Ogreman::NNotesComponent::GetTotalNotas() {
	return totalnotas;
}

bool Ogreman::NNotesComponent::TotalNotes() {
	return numnotes == totalnotas;
}
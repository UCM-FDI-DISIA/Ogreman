#pragma once
#ifndef NNOTESCOMPONENT
#define NNOTESCOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"

#pragma warning(disable : 4251)
namespace VeryReal{
	class UITransformComponent;
	class UITextComponent;
}
namespace Ogreman {
	class OGREMAN_API NNotesComponent : public VeryReal::Component {
	public:
		std::pair<bool, std::string>  InitComponent(int notes, int totalnotas);
		void RestaNota();
		int GetNNota();
		int GetTotalNotas();
		bool TotalNotes();
		virtual void Update(const double& dt);
	private:
		bool delay_to_finish = false;
		float time_to_finish = 5.5;
		float time_while_finishing = 0;
		int numnotes;
		int totalnotas;
		VeryReal::UITextComponent* texto;
	};
}

#pragma warning(default : 4251)

#endif
#pragma once
#ifndef PLAYERINTERACTIONCOMPONENT
#define PLAYERINTERACTIONCOMPONENT
#include "Component.h"
#include <string>

namespace Ogreman {
	class FlashlightComponent;
	class NoteComponent;
}

namespace Ogreman {
	class PlayerInteractionComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		void GetCell();
		void GetNote(NoteComponent* note);
	private:
		FlashlightComponent* my_flashlight_component;
		NoteComponent* my_note_component;

	};
}
#endif


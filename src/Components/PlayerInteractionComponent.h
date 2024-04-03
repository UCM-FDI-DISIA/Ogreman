#pragma once
#ifndef PLAYERINTERACTIONCOMPONENT
#define PLAYERINTERACTIONCOMPONENT
#include "Component.h"
#include <string>

namespace Ogreman {
	class FlashlightComponent;
}
namespace Ogreman {
	class NoteComponent;
}

namespace VeryReal {
	class PlayerInteractionComponent : public Component {
	public:
		virtual bool InitComponent();
		void GetCell();
		void GetNote(NoteComponent* note);
	private:
		Ogreman::FlashlightComponent* my_flashlight_component;
		Ogreman::NoteComponent* my_note_component;

	};
}
#endif


#pragma once
#ifndef PLAYERINTERACTIONCOMPONENT
#define PLAYERINTERACTIONCOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"
namespace Ogreman {
	class FlashlightComponent;
}

namespace Ogreman {
	class OGREMAN_API PlayerInteractionComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		void GetCell();
		void GetNote(std::string note);
	private:
		FlashlightComponent* my_flashlight_component;
		std::string my_text;

	};
}
#endif


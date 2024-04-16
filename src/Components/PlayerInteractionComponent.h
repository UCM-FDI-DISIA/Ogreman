#pragma once
#ifndef PLAYERINTERACTIONCOMPONENT
#define PLAYERINTERACTIONCOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"
namespace Ogreman {
	class FlashlightComponent;
}

#pragma warning(disable : 4251)

namespace Ogreman {
	class OGREMAN_API PlayerInteractionComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();
		void GetCell();
		void GetNote(std::string note);
	private:
		FlashlightComponent* my_flashlight_component = nullptr;
		std::string my_text = "";
	};
}

#pragma warning(default : 4251)

#endif
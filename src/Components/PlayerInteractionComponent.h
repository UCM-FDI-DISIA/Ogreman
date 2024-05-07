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
		std::pair<bool, std::string>  InitComponent();
		void GetCell();
		
	private:
		FlashlightComponent* my_flashlight_component = nullptr;
	};
}

#pragma warning(default : 4251)

#endif
#pragma once
#ifndef CELLCOMPONENT
#define CELLCOMPONENT
#include "Component.h"
#include <iostream>
#include "../Export.h"

namespace VeryReal {
	class AudioSourceComponent;
}

namespace Ogreman {
	class OGREMAN_API CellComponent : public VeryReal::Component {
	public:

		virtual ~CellComponent() {};
		std::pair<bool,std::string> InitComponent();
		void PlayPickUpSound();
	private:
		bool pickedUp;
		VeryReal::AudioSourceComponent* my_audio_source;
	};
}
#endif

#pragma once
#ifndef NOTECOMPONENT
#define NOTECOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"

#pragma warning(disable : 4251)
namespace VeryReal {
	class AudioSourceComponent;
}

namespace Ogreman {
	class OGREMAN_API NoteComponent : public VeryReal::Component {
	public:
		std::pair<bool, std::string>  InitComponent(std::string text_);
		std::string getText();
		void PlayPickUpSound();
	private:
		bool pickedUp = false;
		std::string textt = "";
		VeryReal::AudioSourceComponent* my_audio_source;
	};
}

#pragma warning(default : 4251)

#endif
#pragma once
#ifndef NOTECOMPONENT
#define NOTECOMPONENT
#include "Component.h"
#include <string>

namespace Ogreman {
	class NoteComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent(std::string text_);

	private:
		bool pickedUp;
		std::string text;
	};
}
#endif


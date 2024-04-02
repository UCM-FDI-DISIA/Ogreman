#pragma once
#ifndef NOTECOMPONENT
#define NOTECOMPONENT
#include "Component.h"
#include <string>

namespace VeryReal {
	class NoteComponent : public Component {
	public:
		virtual bool InitComponent(std::string text_);

	private:
		bool pickedUp;
		std::string text;
	};
}
#endif


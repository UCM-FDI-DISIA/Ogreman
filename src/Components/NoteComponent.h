#pragma once
#ifndef NOTECOMPONENT
#define NOTECOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API NoteComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent(std::string text_);
		std::string getText();
	private:
		bool pickedUp;
		std::string text;
	};
}
#endif


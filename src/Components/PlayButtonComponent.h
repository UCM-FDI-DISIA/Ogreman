#pragma once
#ifndef PLAYBUTTONCOMPONENT
#define PLAYBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace Ogreman {
	class OGREMAN_API PlayButtonComponent : public VeryReal::UIButtonComponent {
	public:		
		virtual void Action();
	};
}
#endif

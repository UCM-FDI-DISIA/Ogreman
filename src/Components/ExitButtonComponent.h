#pragma once
#ifndef EXITBUTTONCOMPONENT
#define EXITBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace Ogreman {
	class OGREMAN_API ExitButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual bool InitComponent();
		virtual void accion();
	};
}
#endif

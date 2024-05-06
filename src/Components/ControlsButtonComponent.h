#pragma once
#ifndef CONTROLSBUTTONCOMPONENT
#define CONTROLSBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace Ogreman {
	class OGREMAN_API ControlsButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual void accion();
	};
}
#endif


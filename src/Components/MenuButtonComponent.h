#pragma once
#ifndef MENUBUTTONCOMPONENT
#define MENUBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace Ogreman {
	class OGREMAN_API MenuButtonComponent : public VeryReal::UIButtonComponent {
	public:
		virtual bool InitComponent();
		virtual void accion();
	};
}
#endif
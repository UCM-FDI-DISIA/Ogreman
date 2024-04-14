#pragma once
#ifndef PLAYBUTTONCOMPONENT
#define PLAYBUTTONCOMPONENT
#include <UI/UIButtonComponent.h>
#include "../Export.h"

namespace Ogreman {
	class OGREMAN_API PlayButtonComponent : public VeryReal::UIButtomComponent {
	public:
		virtual bool InitComponent();
		virtual void accion();
	};
}
#endif

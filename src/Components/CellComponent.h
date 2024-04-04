#pragma once
#ifndef CELLCOMPONENT
#define CELLCOMPONENT
#include "Component.h"
#include <string>

namespace Ogreman {
	class CellComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();

	private:
		bool pickedUp;
	};
}
#endif

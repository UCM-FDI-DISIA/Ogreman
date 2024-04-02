#pragma once
#ifndef CELLCOMPONENT
#define CELLCOMPONENT
#include "Component.h"
#include <string>

namespace VeryReal {
	class CellComponent : public Component {
	public:
		virtual bool InitComponent();

	private:
		bool pickedUp;
	};
}
#endif

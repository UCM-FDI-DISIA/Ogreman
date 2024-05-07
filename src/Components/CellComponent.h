#pragma once
#ifndef CELLCOMPONENT
#define CELLCOMPONENT
#include "Component.h"
#include <iostream>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CellComponent : public VeryReal::Component {
	public:

		virtual ~CellComponent() {};
		std::pair<bool,std::string> InitComponent();

	private:
		bool pickedUp;
	};
}
#endif

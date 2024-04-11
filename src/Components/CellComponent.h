#pragma once
#ifndef CELLCOMPONENT
#define CELLCOMPONENT
#include "Component.h"
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CellComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent();

	private:
		bool pickedUp;
	};
}
#endif

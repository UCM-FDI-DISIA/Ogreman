#pragma once
#ifndef NNOTESCOMPONENT
#define NNOTESCOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"

#pragma warning(disable : 4251)
namespace VeryReal{
	class UITransformComponent;
}
namespace Ogreman {
	class OGREMAN_API NNotesComponent : public VeryReal::Component {
	public:
		virtual bool InitComponent(int notes, int totalnotas);
		void restanota();
		int getnnota();
		int getotalnotas();
		bool totalnotes();
	private:
		int numnotes;
		int totalnotas;
	};
}

#pragma warning(default : 4251)

#endif
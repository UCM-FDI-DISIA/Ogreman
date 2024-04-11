#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorNoteComponent : public VeryReal::CreatorComponent{
	private:
	public:
		CreatorNoteComponent() {}
		virtual ~CreatorNoteComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}


#pragma once
#include <CreatorComponent.h>
namespace Ogreman {
	class CreatorNoteComponent : public VeryReal::CreatorComponent{
	private:
	public:
		CreatorNoteComponent() {}
		virtual ~CreatorNoteComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}


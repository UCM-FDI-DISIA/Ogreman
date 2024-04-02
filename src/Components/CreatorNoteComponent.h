#pragma once
#include <CreatorComponent.h>
namespace VeryReal {
	class CreatorNoteComponent : public CreatorComponent {
	private:
	public:
		CreatorNoteComponent() {}
		virtual ~CreatorNoteComponent() {}
		Component* CreatorSpecificComponent() override;
	};
}


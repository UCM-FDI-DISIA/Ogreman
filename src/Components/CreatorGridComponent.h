#pragma once

#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorGridComponent: public VeryReal::CreatorComponent
	{
	public:
		CreatorGridComponent() {}
		virtual ~CreatorGridComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	protected:
	};
}

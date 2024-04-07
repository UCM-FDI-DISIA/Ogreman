#pragma once
#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorNodeComponent : public VeryReal::CreatorComponent
	{
	public:
		CreatorNodeComponent() {}
		virtual ~CreatorNodeComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	protected:

	};

}
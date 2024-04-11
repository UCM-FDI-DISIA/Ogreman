#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorNodeComponent : public VeryReal::CreatorComponent
	{
	public:
		CreatorNodeComponent() {}
		virtual ~CreatorNodeComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	protected:

	};

}
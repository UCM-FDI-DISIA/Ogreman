#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorRangosVisionComponent : public VeryReal::CreatorComponent
	{
	public:
		CreatorRangosVisionComponent() {}
		virtual ~CreatorRangosVisionComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	protected:

	};

}
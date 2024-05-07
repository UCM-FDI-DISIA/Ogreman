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
		std::pair<bool, std::string>  SpecificInitComponent(VeryReal::Component* c) override;
		std::pair<bool, std::string>  SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	protected:

	};

}
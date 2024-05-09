#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorTransformFollowComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorTransformFollowComponent() {}
		virtual ~CreatorTransformFollowComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		std::pair<bool, std::string>  SpecificInitComponent(VeryReal::Component* c) override;
		std::pair<bool, std::string>  SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
}


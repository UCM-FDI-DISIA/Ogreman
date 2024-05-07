#pragma once
#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorOgremanHearingComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorOgremanHearingComponent() {}
		virtual ~CreatorOgremanHearingComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		std::pair<bool, std::string> SpecificInitComponent(VeryReal::Component* c) override;
		std::pair<bool, std::string> SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
}
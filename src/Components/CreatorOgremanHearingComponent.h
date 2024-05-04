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
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
}
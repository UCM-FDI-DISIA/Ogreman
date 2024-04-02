#pragma once
#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorFlashlightComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorFlashlightComponent() {}
		virtual ~CreatorFlashlightComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
	};
}

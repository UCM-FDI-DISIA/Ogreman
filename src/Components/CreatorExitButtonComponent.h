#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorExitButtonComponent : public VeryReal::CreatorComponent {
	public:
		CreatorExitButtonComponent() {}
		virtual ~CreatorExitButtonComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
}


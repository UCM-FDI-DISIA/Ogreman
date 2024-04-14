#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorPlayButtonComponent : public VeryReal::CreatorComponent {
	public:
		CreatorPlayButtonComponent() {}
		virtual ~CreatorPlayButtonComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}

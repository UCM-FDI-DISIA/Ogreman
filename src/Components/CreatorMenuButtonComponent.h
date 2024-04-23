#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorMenuButtonComponent : public VeryReal::CreatorComponent {
	public:
		CreatorMenuButtonComponent() {}
		virtual ~CreatorMenuButtonComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}


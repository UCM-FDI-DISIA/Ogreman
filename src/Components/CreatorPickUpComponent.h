#pragma once
#include <CreatorComponent.h>
namespace Ogreman {
	class CreatorPickUpComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorPickUpComponent() {}
		virtual ~CreatorPickUpComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}


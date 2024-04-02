#pragma once
#include <CreatorComponent.h>
namespace VeryReal {
	class CreatorPickUpComponent : public CreatorComponent {
	private:
	public:
		CreatorPickUpComponent() {}
		virtual ~CreatorPickUpComponent() {}
		Component* CreatorSpecificComponent() override;
	};
}


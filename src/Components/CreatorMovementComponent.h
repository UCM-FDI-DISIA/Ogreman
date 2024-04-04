#pragma once
#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorMovementComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorMovementComponent() {}
		virtual ~CreatorMovementComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}

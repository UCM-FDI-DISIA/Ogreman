#pragma once
#include <CreatorComponent.h>
namespace VeryReal {
	class CreatorMovementComponent : public CreatorComponent {
	private:
	public:
		CreatorMovementComponent() {}
		virtual ~CreatorMovementComponent() {}
		Component* CreatorSpecificComponent() override;
	};
}

#pragma once
#include <CreatorComponent.h>

namespace VeryReal {
	class CreatorOgremanAttackComponent : public CreatorComponent {
	private:
	public:
		CreatorOgremanAttackComponent() {}
		virtual ~CreatorOgremanAttackComponent() {}
		Component* CreatorSpecificComponent() override;
	};
};
#pragma once
#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorOgremanAttackComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorOgremanAttackComponent() {}
		virtual ~CreatorOgremanAttackComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
};
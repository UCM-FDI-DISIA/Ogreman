#pragma once
#include <CreatorComponent.h>

namespace Ogreman {
	class CreatorPlayerInputComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorPlayerInputComponent() {}
		virtual ~CreatorPlayerInputComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
};
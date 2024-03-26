#pragma once
#include <CreatorComponent.h>

namespace VeryReal {
	class CreatorPlayerInputComponent : public CreatorComponent {
	private:
	public:
		CreatorPlayerInputComponent() {}
		virtual ~CreatorPlayerInputComponent() {}
		Component* CreatorSpecificComponent() override;
	};
};
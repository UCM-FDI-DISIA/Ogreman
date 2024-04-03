#pragma once
#include <CreatorComponent.h>
namespace VeryReal {
	class CreatorPlayerInteractionComponent : public CreatorComponent {
	private:
	public:
		CreatorPlayerInteractionComponent() {}
		virtual ~CreatorPlayerInteractionComponent() {}
		Component* CreatorSpecificComponent() override;
	};
}
#pragma once
#include <CreatorComponent.h>
namespace Ogreman {
	class CreatorPlayerInteractionComponent : public VeryReal::CreatorComponent{
	private:
	public:
		CreatorPlayerInteractionComponent() {}
		virtual ~CreatorPlayerInteractionComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}
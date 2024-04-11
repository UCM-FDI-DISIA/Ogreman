#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorPlayerInteractionComponent : public VeryReal::CreatorComponent{
	private:
	public:
		CreatorPlayerInteractionComponent() {}
		virtual ~CreatorPlayerInteractionComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}
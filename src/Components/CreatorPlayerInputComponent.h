#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorPlayerInputComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorPlayerInputComponent() {}
		virtual ~CreatorPlayerInputComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
		void SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
	};
};
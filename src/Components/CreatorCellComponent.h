#pragma once
#include <CreatorComponent.h>
namespace Ogreman {
	class CreatorCellComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorCellComponent() {}
		virtual ~CreatorCellComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}

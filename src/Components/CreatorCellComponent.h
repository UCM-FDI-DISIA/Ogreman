#pragma once
#include <CreatorComponent.h>
#include "../Export.h"
namespace Ogreman {
	class OGREMAN_API CreatorCellComponent : public VeryReal::CreatorComponent {
	private:
	public:
		CreatorCellComponent() {}
		virtual ~CreatorCellComponent() {}
		VeryReal::Component* CreatorSpecificComponent() override;
		void SpecificInitComponent(VeryReal::Component* c) override;
	};
}

#pragma once
#include <CreatorComponent.h>
namespace VeryReal {
	class CreatorCellComponent : public CreatorComponent {
	private:
	public:
		CreatorCellComponent() {}
		virtual ~CreatorCellComponent() {}
		Component* CreatorSpecificComponent() override;
	};
}

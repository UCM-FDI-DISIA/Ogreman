#pragma once
#ifndef NNOTESCOMPONENT
#define NNOTESCOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"

#pragma warning(disable : 4251)
namespace VeryReal {
	class TransformComponent;
}
namespace Ogreman {
	class OGREMAN_API TransformFollowComponent : public VeryReal::Component {
	public:
		std::pair<bool, std::string>  InitComponent(std::string targetEntityName);
		virtual void Update(const double& dt);
	private:
		VeryReal::TransformComponent* target_transform;
		VeryReal::TransformComponent* my_transform;
	};
}

#pragma warning(default : 4251)

#endif
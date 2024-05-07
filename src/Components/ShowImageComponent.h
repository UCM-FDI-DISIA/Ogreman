#pragma once
#ifndef SHOWIMAGECOMPONENT
#define SHOWIMAGECOMPONENT
#include "Component.h"
#include <string>
#include "../Export.h"

#pragma warning(disable : 4251)
namespace VeryReal{
	class UITransformComponent;
}
namespace Ogreman {
	class OGREMAN_API ShowImageComponent : public VeryReal::Component {
	public:
		std::pair<bool, std::string>  InitComponent(double ttoshow);
		virtual void Update(const double& dt);
		void activeTime();
		inline float getTimeToShow() { return time_toshow; }
	private:
		bool active;
		double time_toshow;
		VeryReal::UITransformComponent* uitr;
	};
}

#pragma warning(default : 4251)

#endif
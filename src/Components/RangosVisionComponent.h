#pragma once
#ifndef RANGOSVISIONCOMPONENT
#define RANGOSVISIONCOMPONENT
#include "Component.h"
#include  "../Export.h"

namespace Ogreman {
	class OGREMAN_API RangosVisionComponent : public VeryReal::Component {
	public:
		RangosVisionComponent();
		virtual ~RangosVisionComponent();
		virtual bool InitComponent(float maxv , float minv, float maxt, float mint);

	private:
		float maxvision, minvision;
		float maxtam, mintam;
		
	};
}
#endif


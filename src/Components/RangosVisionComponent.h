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
		float GetmaxVision();
		float GetminVision();
		float GetmaxTam();
		float GetminTam();
		float GetTamDif();
		float GetVisionDif();
	private:
		float maxvision = 0, minvision = 0;
		float maxtam = 0, mintam = 0;
		
	};
}
#endif


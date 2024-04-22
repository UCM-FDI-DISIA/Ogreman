#include "RangosVisionComponent.h"
#include <TransformComponent.h>
 Ogreman::RangosVisionComponent::RangosVisionComponent() {



}
  Ogreman::RangosVisionComponent::~RangosVisionComponent() {

	
}

bool Ogreman::RangosVisionComponent::InitComponent(float maxv, float minv, float maxt, float mint) {
	maxvision = maxv;
	if (maxtam > 1000)maxtam = 1000;
	minvision = minv;
	if (minvision < 0.1)minvision = 0.1;
	maxtam = maxt;
	if (maxtam > 1)maxtam = 1;
	mintam = mint;
	if (mintam < 0.1)mintam = 0.1;
	return true;
}

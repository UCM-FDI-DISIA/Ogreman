#include "RangosVisionComponent.h"
#include <TransformComponent.h>
 Ogreman::RangosVisionComponent::RangosVisionComponent() {



}
  Ogreman::RangosVisionComponent::~RangosVisionComponent() {

	
}

  std::pair<bool, std::string>  Ogreman::RangosVisionComponent::InitComponent(float maxv, float minv, float maxt, float mint) {
	  maxvision = maxv;
	  if (maxtam > 1000)maxtam = 1000;
	  minvision = minv;
	  if (minvision < 0.1)minvision = 0.1f;
	  maxtam = maxt;
	  if (maxtam > 1)maxtam = 1;
	  mintam = mint;
	  if (mintam < 0.1)mintam = 0.1f;
	  
	  return { true, " " };
  }

float  Ogreman::RangosVisionComponent::GetmaxVision() {
	return maxvision;
}
float  Ogreman::RangosVisionComponent::GetminVision() {
	return minvision;
}
float  Ogreman::RangosVisionComponent::GetmaxTam() {
	return maxtam;
}
float  Ogreman::RangosVisionComponent::GetminTam() {
	return mintam;
}
float  Ogreman::RangosVisionComponent::GetTamDif() {
	return (maxtam - mintam);
}
float  Ogreman::RangosVisionComponent::GetVisionDif() {
	return (maxvision- minvision);
}
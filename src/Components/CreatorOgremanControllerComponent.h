#pragma once
#include <CreatorComponent.h>

class CreatorOgremanControllerComponent: public VeryReal::CreatorComponent
{
public:
	CreatorOgremanControllerComponent() { };
	virtual ~CreatorOgremanControllerComponent() {};
	VeryReal::Component* CreatorSpecificComponent() override;
	void SpecificInitComponent(VeryReal::Component* c) override;
};


#pragma once
#include "CreatorComponent.h"
#include "../Export.h"


namespace Ogreman {
class OGREMAN_API CreatorSmokeComponent : public VeryReal::CreatorComponent{
    private:
    public:
        CreatorSmokeComponent() { }
        virtual ~CreatorSmokeComponent() { }
        VeryReal::Component* CreatorSpecificComponent() override;
        std::pair<bool, std::string> SpecificInitComponent(VeryReal::Component* c) override;
        std::pair<bool, std::string> SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) override;
    };
}

#pragma once
#ifndef SMOKECOMPONENT_H
#define SMOKECOMPONENT_H

#include "Component.h"
#include "Vector3.h"
#include "../Export.h"

namespace VeryReal {
    class Vector3;
    class Entity;
    class TransformComponent;
    class SmokeEffect;
}

#pragma warning(disable : 4251)

namespace Ogreman {
    class OGREMAN_API SmokeComponent : public VeryReal::Component {
    private:
        VeryReal::Entity* smokeEntity = nullptr;
        float duration = 5.0f;
        float remainingDuration = 0;

    public:
        SmokeComponent();
        virtual std::pair<bool, std::string> InitComponent();
        virtual void Update(const double& dt);
        void CreateSmokeEffect(const VeryReal::Vector3& position);
    };
}

#pragma warning(default : 4251)

#endif // SMOKECOMPONENT_H

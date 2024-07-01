#pragma once
#ifndef SMOKECREATORCOMPONENT_H
#define SMOKECREATORCOMPONENT_H
#include "Component.h"
#include "Vector3.h"
#include "../Export.h"

namespace VeryReal {
    class Vector3;
    class Entity;
    class TransformComponent;
}

#pragma warning(disable : 4251)

namespace Ogreman {
    class OGREMAN_API SmokeComponent : public VeryReal::Component {
    private:
        float duration = 5000 ;

    public:
        SmokeComponent();
        virtual std::pair<bool, std::string> InitComponent();
        virtual void Update(const double& dt);
        void CreateSmokeEffect(const VeryReal::Vector3& position, int numB);

    };
}

#pragma warning(default : 4251)

#endif // SMOKECREATORCOMPONENT_H

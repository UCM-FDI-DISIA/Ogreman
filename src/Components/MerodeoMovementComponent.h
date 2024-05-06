#pragma once
#ifndef MERODEOMOVEMENTCOMPONENT
#define MERODEOMOVEMENTCOMPONENT
#include "Component.h"
#include "../Export.h"
#include "Vector3.h"

namespace VeryReal {
	class TransformComponent;
	class RigidBodyComponent;
	
}
namespace Ogreman
{
	class OGREMAN_API MerodeoMovementComponent : public VeryReal::Component {
	private:
		//cada cuanto cambia de direccion
		int timertochange;
		//cuanto tiempo llevo desde el cambio
		double actualtimer;
		//radio maximo entre el que puede cambiar
		float wanderRange;
		float aceleration;
		VeryReal::Vector3 nextvel;
		float velocityx, velocityz;
		//rigidbody de la entidad
		VeryReal::RigidBodyComponent* rigidbodycomponent;
		VeryReal::TransformComponent* transfrormcomponent;
		float random360();

	public:
		MerodeoMovementComponent();
		bool InitComponent();
		virtual ~MerodeoMovementComponent();
		void Update(const double& dt) override;
		float RotationY(VeryReal::Vector3& vector1, VeryReal::Vector3& vector2);

	};
}

#endif


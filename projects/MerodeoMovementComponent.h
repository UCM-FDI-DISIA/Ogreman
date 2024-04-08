#pragma once
#ifndef MERODEOMOVEMENTCOMPONENT
#define MERODEOMOVEMENTCOMPONENT
#include "Component.h"
using namespace VeryReal;
namespace VeryReal {
	class TransformComponent;
	class RigidBodyComponent;
}
namespace Ogreman
{
	class MerodeoMovementComponent : public Component {
	private:
		//cada cuanto cambia de direccion
		int timertochange;
		//cuanto tiempo llevo desde el cambio
		int actualtimer;
		//radio maximo entre el que puede cambiar
		float wanderRange;
		float aceleration;
		//rigidbody de la entidad
		RigidBodyComponent* rigidbodycomponent;
		TransformComponent* transfrormcomponent;
		int random360();

	public:
		MerodeoMovementComponent();
		virtual ~MerodeoMovementComponent();
		void Update(const double& dt) override;

	};
}

#endif


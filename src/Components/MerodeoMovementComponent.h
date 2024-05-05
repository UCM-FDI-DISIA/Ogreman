#pragma once
#ifndef MERODEOMOVEMENTCOMPONENT
#define MERODEOMOVEMENTCOMPONENT
#include "Component.h"
#include "../Export.h"

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

		float velocityx, velocityz;
		//rigidbody de la entidad
		VeryReal::RigidBodyComponent* rigidbodycomponent;
		VeryReal::TransformComponent* transfrormcomponent;
		int random360();

	public:
		MerodeoMovementComponent();
		bool InitComponent();
		virtual ~MerodeoMovementComponent();
		void Update(const double& dt) override;

	};
}

#endif


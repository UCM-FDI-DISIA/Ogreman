#pragma once
#ifndef MERODEOMOVEMENTCOMPONENT
#define MERODEOMOVEMENTCOMPONENT
#include "Component.h"
#include "../Export.h"
using namespace VeryReal;
namespace VeryReal {
	class TransformComponent;
	class RigidBodyComponent;
}
namespace Ogreman
{
	class OGREMAN_API MerodeoMovementComponent : public Component {
	private:
		//cada cuanto cambia de direccion
		int timertochange;
		//cuanto tiempo llevo desde el cambio
		double actualtimer;
		//radio maximo entre el que puede cambiar
		float wanderRange;
		float aceleration;
		//rigidbody de la entidad
		RigidBodyComponent* rigidbodycomponent;
		TransformComponent* transfrormcomponent;
		int random360();

	public:
		MerodeoMovementComponent();
		bool InitComponent();
		virtual ~MerodeoMovementComponent();
		void Update(const double& dt) override;

	};
}

#endif


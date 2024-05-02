#pragma once
//Calculo el radio de audición en función de la intensidad del sonido emitido por el jugador (referirse a la formula de chat gpt)
// radioMaximo * (exp(k * intensidad) - 1) / (exp(k) - 1);
//Luego compruebo si la distancia entre el jugador y el ogro es menor que dicho radio
//En caso afirmativo pongo a true la persecución, en caso contrario devuelvo false


//necesito:
//La sensibilidad de escucha del ogro, viene a ser el radio máximo del circulo imaginario alrededor del jugador en función de la intensidad del sonido emitido
// Transform del jugador 
// Transform del ogro
// bool de detección o no
// getter de la intensidad de audioleon
#ifndef OGREMANHEARINGCOMPONENT
#define OGREMANHEARINGCOMPONENT

#include "Component.h"
#include "Vector3.h"
#include "../Export.h"
namespace VeryReal {
	class TransformComponent;
}

namespace Ogreman
{
	class PlayerInputComponent;
	class OGREMAN_API OgremanHearingComponent : public VeryReal::Component
	{
	public:
		virtual bool InitComponent();
		virtual void Update(const double& dt);
		float CalculateRadius(float intensity);
		bool GetDetected();

	private:
		VeryReal::TransformComponent* my_transform = nullptr;
		VeryReal::TransformComponent* player_transform = nullptr;
		PlayerInputComponent* player_input = nullptr;
		bool player_detected = false; 
		//Intgensidad del ruido emitido por el jugador.
		float player_noise_intensity;
		//Distancia máxima desde la que el ogro te escucha.
		int ogre_sound_sensitivity;
		//Radio de la circunferencia alrededor del jugador
		//que establece hasta donde se le oye
		float hearing_radius = 0;
		//Factor de crecimiento de la función exponencial que calcula la distancia
		//a la que se escucha al jugador en una circunferencia alrededor del mismo
		float radius_growth_rate;
	};
}

#endif
#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "RigidBodyComponent.h"
#include"ComponentesAudio/AudioListenerComponent.h"
#include"ComponentesAudio/AudioSourceComponent.h"
#include <string>
#include "Vector3.h"

namespace VeryReal {
    // AudioEmitterComponent actúa como un emisor de sonido dentro del entorno de juego,
    // permitiendo una gestión detallada de cómo se emiten y perciben los sonidos.
    class AudioEmitterComponent : public Component {
    public:
        AudioEmitterComponent();
        virtual ~AudioEmitterComponent();

        // Inicializa el componente con propiedades específicas para la emisión de audio.
        bool InitComponent(const std::string& soundName, const std::string& soundPath, bool loop = false, float volume = 1.0f, bool playOnStart = false, bool is3D = true);

        void Play();
        void Stop();
        void Pause();
        void Resume();
        void Update(const double& dt) override;

    private:
        std::string soundName;
        std::string soundPath;
        bool loop;
        float volume;
        bool playOnStart;
        bool isPlaying;
        bool is3D; // Indica si el sonido se manejará como 3D.

        TransformComponent* transform;
        RigidBodyComponent* rigidBody;
        AudioSourceComponent* audioSource;

        // Métodos específicos de emisión de sonido.
        void Set3DSoundAttributes();
        void ApplyEnvironmentalEffects(); // Aplica efectos ambientales al sonido, como la reverberación.
        std::string DetermineEnvironment(const Vector3& position);
    };
}

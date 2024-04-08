#include "AudioEmitterComponent.h"
#include "AudioLeon.h"
#include "ComponentesAudio/AudioSourceComponent.h"
#include <ErrorInformant.h>
#include "Entity.h"

using namespace VeryReal;
using namespace Ogreman;

AudioEmitterComponent::AudioEmitterComponent() : loop(false), volume(1.0f), playOnStart(false), isPlaying(false), is3D(true), transform(nullptr), rigidBody(nullptr), audioSource(nullptr) {
}

AudioEmitterComponent::~AudioEmitterComponent() {
    delete audioSource;
}

bool AudioEmitterComponent::InitComponent(const std::string& soundName, const std::string& soundPath, bool loop, float volume, bool playOnStart, bool is3D) {
    this->soundName = soundName;
    this->soundPath = soundPath;
    this->loop = loop;
    this->volume = volume;
    this->playOnStart = playOnStart;
    this->is3D = is3D;

    transform = this->GetEntity()->GetComponent<TransformComponent>("TransformComponent");
    rigidBody = this->GetEntity()->GetComponent<RigidBodyComponent>("RigidBodyComponent");

    if (!transform || (is3D && !rigidBody)) {
        ErrorInf().showErrorMessageBox("AudioEmitterComponent error", "Entity does not have required components.", EI_ERROR);
        return false;
    }

    audioSource = new AudioSourceComponent();
    bool success = audioSource->InitComponent(soundName, soundPath, playOnStart, "default", volume, is3D, loop, 1.0f, 1000.0f);

    if (!success) {
        delete audioSource;
        audioSource = nullptr;
        return false;
    }

    if (playOnStart) {
        Play();
    }

    return true;
}

void AudioEmitterComponent::Play() {
    if (audioSource && !isPlaying) {
        audioSource->Play();
        isPlaying = true;
    }
}

void AudioEmitterComponent::Stop() {
    if (audioSource && isPlaying) {
        audioSource->Stop();
        isPlaying = false;
    }
}

void AudioEmitterComponent::Pause() {
    if (audioSource && isPlaying) {
        audioSource->Pause();
    }
}

void AudioEmitterComponent::Resume() {
    if (audioSource && !isPlaying) {
        audioSource->Resume();
        isPlaying = true;
    }
}

void AudioEmitterComponent::Update(const double& dt) {
    if (audioSource && isPlaying && is3D) {
        Set3DSoundAttributes();
        ApplyEnvironmentalEffects();
    }
}

void AudioEmitterComponent::Set3DSoundAttributes() {
    if (!transform || !rigidBody || !audioSource) return;

    Vector3 pos = transform->GetPosition();
    Vector3 vel = rigidBody->GetVelocity();
    audioSource->Set3DSoundAtributes(soundName, pos, vel);
}

void AudioEmitterComponent::ApplyEnvironmentalEffects() {
    // Asumiendo que tenemos acceso a la posición del emisor y podemos determinar el entorno basado en esta.
    Vector3 position = transform->GetPosition();

    std::string environment = DetermineEnvironment(position);

    //FMOD_REVERB_PROPERTIES prop = FMOD_PRESET_GENERIC; // Preset por defecto.

    //// Ajustar las propiedades de reverberación basadas en el entorno.
    //if (environment == "cave") {
    //    prop = FMOD_PRESET_CAVE;
    //}
    //else if (environment == "underwater") {
    //    prop = FMOD_PRESET_UNDERWATER;
    //}
    //else if (environment == "concerthall") {
    //    prop = FMOD_PRESET_CONCERTHALL;
    //}

    // Aplicar el preset de reverberación seleccionado.

    // Activar el efecto de reverberación.
}

std::string AudioEmitterComponent::DetermineEnvironment(const Vector3& position) {///ejemplo para el ambiente
    if (position.GetZ() < -10) {
        return "cave";
    }
    else if (position.GetY() < 0) {
        return "underwater";
    }
    else {
        return "openfield";
    }
}


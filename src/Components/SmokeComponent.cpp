#include "SmokeComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include "TransformComponent.h"
#include <iostream> // Para los logs
#include "SmokeEffect.h"

Ogreman::SmokeComponent::SmokeComponent() { }

std::pair<bool, std::string> Ogreman::SmokeComponent::InitComponent() {
    return { true, "SmokeComponent created correctly" };
}

void Ogreman::SmokeComponent::Update(const double& dt) {
    if (smokeEntity) {
        remainingDuration -= dt;
        if (remainingDuration <= 0) {
            VeryReal::SmokeEffect* smokeEffect = smokeEntity->GetComponent<VeryReal::SmokeEffect>();
            if (smokeEffect) {
                smokeEffect->setApagado();
                std::cout << "SmokeEffect turned off." << std::endl;
            }
        }
    }
}

void Ogreman::SmokeComponent::CreateSmokeEffect(const VeryReal::Vector3& position) {
    if (!smokeEntity) {
        smokeEntity = VeryReal::SceneManager::Instance()->GetActiveScene()->GetEntity("smoke");
        if (!smokeEntity) {
            std::cout << "Creating SmokeEffect for the first time at Position: " << position.GetX() << ", " << position.GetY() << ", " << position.GetZ() << std::endl;
            smokeEntity = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabSmoke", "smoke");
            if (!smokeEntity) {
                std::cout << "Failed to create smoke\n";
                return;
            }
        }
        else {
            std::cout << "Reusing existing SmokeEffect entity." << std::endl;
        }
    }
    else {
        std::cout << "Reusing SmokeEffect at Position: " << position.GetX() << ", " << position.GetY() << ", " << position.GetZ() << std::endl;
    }

    VeryReal::TransformComponent* smoke_transform = smokeEntity->GetComponent<VeryReal::TransformComponent>();
    if (smoke_transform) {
        VeryReal::SmokeEffect* smokeEffect = smokeEntity->GetComponent<VeryReal::SmokeEffect>();
        if (smokeEffect) {
            smokeEffect->setEncendido();
            smokeEffect->setPosition(position);
            smoke_transform->SetPosition(position);
            remainingDuration = duration;
        }
    }
}

#include "SmokeComponent.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Entity.h"
#include "TransformComponent.h"
#include <iostream> // Para los logs


Ogreman::SmokeComponent::SmokeComponent() { }

std::pair<bool, std::string> Ogreman::SmokeComponent::InitComponent() {
    return { true, "SmokeComponent created correctly" };
}

void Ogreman::SmokeComponent::Update(const double& dt) {
    duration -= dt;
    std::cout << "Updating SmokeEffect. Remaining Duration: " << duration << std::endl;
    if (duration <= 0) {
        this->GetEntity()->SetActive(false);
        return;
    }
}

void Ogreman::SmokeComponent::CreateSmokeEffect(const VeryReal::Vector3& position, int numB) {
    std::cout << "Creating SmokeEffect at Position: " << position.GetX() << ", " << position.GetY() << ", " << position.GetZ() << std::endl;
    VeryReal::Entity* smoke = VeryReal::SceneManager::Instance()->GetActiveScene()->CreatePrefab("PrefabSmoke", "smoke" + std::to_string(numB));
    if (!smoke) {
        std::cout << "Failed to create smoke\n";
        return;
    }

    VeryReal::TransformComponent* smoke_transform = smoke->GetComponent<VeryReal::TransformComponent>();
    if (smoke_transform) {
        smoke_transform->SetPosition(position);

    }
}

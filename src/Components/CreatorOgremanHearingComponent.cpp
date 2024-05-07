#include "CreatorOgremanHearingComponent.h"
#include "OgremanHearingComponent.h"

VeryReal::Component* Ogreman::CreatorOgremanHearingComponent::CreatorSpecificComponent()
{
	return new OgremanHearingComponent();
}

std::pair<bool, std::string> Ogreman::CreatorOgremanHearingComponent::SpecificInitComponent(VeryReal::Component* c)
{
    int sensitivity;
    float rate, lowerThreshold, upperThreshold;
    Ogreman::OgremanHearingComponent* ogrehearing = static_cast<Ogreman::OgremanHearingComponent*>(c);

#pragma region Sensitivity

    if (parameters_map.find("sensitivity") != parameters_map.end()) {
        if (std::holds_alternative<int>(parameters_map.at("sensitivity")->GetVariant())) {
            sensitivity = std::get<int>(parameters_map.at("sensitivity")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para sensitivity este sera seteado por defecto" << std::endl;
            sensitivity = 0;
        }
    }
    else {
        std::cout << "No existe ningun parametro sensitivity este sera seteado por defecto" << std::endl;
        sensitivity = 0;
    }
#pragma endregion

#pragma region Rate

    if (parameters_map.find("rate") != parameters_map.end()) {
        if (std::holds_alternative<float>(parameters_map.at("rate")->GetVariant())) {
            rate = std::get<float>(parameters_map.at("rate")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para rate este sera seteado por defecto" << std::endl;
            rate = 0.0f;
        }
    }
    else {
        std::cout << "No existe ningun parametro rate este sera seteado por defecto" << std::endl;
        rate = 0.0f;
    }
#pragma endregion

#pragma region Lower Threshold

    if (parameters_map.find("lowerThreshold") != parameters_map.end()) {
        if (std::holds_alternative<float>(parameters_map.at("lowerThreshold")->GetVariant())) {
            lowerThreshold = std::get<float>(parameters_map.at("lowerThreshold")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para lowerThreshold este sera seteado por defecto" << std::endl;
            lowerThreshold = 0.0f;
        }
    }
    else {
        std::cout << "No existe ningun parametro lowerThreshold este sera seteado por defecto" << std::endl;
        lowerThreshold = 0.0f;
    }
#pragma endregion

#pragma region Upper Threshold

    if (parameters_map.find("upperThreshold") != parameters_map.end()) {
        if (std::holds_alternative<float>(parameters_map.at("upperThreshold")->GetVariant())) {
            upperThreshold = std::get<float>(parameters_map.at("upperThreshold")->GetVariant());
        }
        else {
            std::cout << "No se ha especificado ningun valor para upperThreshold este sera seteado por defecto" << std::endl;
            upperThreshold = 0.0f;
        }
    }
    else {
        std::cout << "No existe ningun parametro upperThreshold este sera seteado por defecto" << std::endl;
        upperThreshold = 0.0f;
    }
#pragma endregion

    return ogrehearing->InitComponent(rate, sensitivity, lowerThreshold, upperThreshold);
}

std::pair<bool, std::string> Ogreman::CreatorOgremanHearingComponent::SpecificInitComponentByCopy(VeryReal::Component* c, VeryReal::Component* other) {
    return { true, "" };
}
// OgremanSolucion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <RenderManager.h>
#include "CreatorAnimatorComponent.h"
#include "CreatorTransformComponent.h"
#include "Creator.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Entity.h"
#include "Component.h"
#include "CreatorCameraComponent.h"
#include "ComponentesAudio/CreatorAudioListenerComponent.h"
#include "ComponentesAudio/CreatorAudioSourceComponent.h"
#include "Vector3.h"
#include "CreatorLightComponent.h"
#include "CreatorMeshRenderComponent.h"
#include "UI/UISpriteRenderComponent.h" 
#include "SceneManager.h"
#include "../Components/CreatorMovementComponent.h"
#include "../Components/CreatorPlayerInputComponent.h"
#include "CreatorCameraComponent.h"
#include "TransformComponent.h"
#include "CameraComponent.h"
#include "../Components/CreatorCellComponent.h"
#include "../Components/CreatorFlashlightComponent.h"
#include "../Components/CreatorGridComponent.h"
#include "../Components/MovementComponent.h"
#include "../Components/CreatorNodeComponent.h"
#include "../Components/CreatorNoteComponent.h"
#include "../Components/CreatorOgremanAttackComponent.h"
#include "../Components/CreatorPickUpComponent.h"
#include "../Components/CreatorPlayerInputComponent.h"
#include "../Components/CreatorPlayerInteractionComponent.h"
#include "../Components/CreatorFlashlightComponent.h"
using namespace VeryReal;

extern "C"  //Para que al exportar la función de las DLLs los nombres no se contaminen (name mangling), esto es usado por el compilador para permitir la sobrecarga de funciones
{
    // Declaración de la función que deseas exportar

    __declspec(dllexport) bool start() {
        VeryReal::Creator::Instance()->AddCreator("cell", new Ogreman::CreatorCellComponent());
        VeryReal::Creator::Instance()->AddCreator("flashlight", new Ogreman::CreatorFlashlightComponent());
        VeryReal::Creator::Instance()->AddCreator("grid", new Ogreman::CreatorGridComponent());
        VeryReal::Creator::Instance()->AddCreator("MovementComponent", new Ogreman::CreatorMovementComponent());
        VeryReal::Creator::Instance()->AddCreator("node", new Ogreman::CreatorNodeComponent());
        VeryReal::Creator::Instance()->AddCreator("note", new Ogreman::CreatorNoteComponent());
        VeryReal::Creator::Instance()->AddCreator("pickup", new Ogreman::CreatorPickUpComponent());
        VeryReal::Creator::Instance()->AddCreator("input", new Ogreman::CreatorPlayerInputComponent());
        VeryReal::Creator::Instance()->AddCreator("playerinteraction", new Ogreman::CreatorPlayerInteractionComponent());
        VeryReal::Creator::Instance()->AddCreator("flashlight", new Ogreman::CreatorFlashlightComponent());
        return true;
    }

    __declspec(dllexport) int main() {
        VeryReal::RenderManager::Instance()->InitManager("app");
        VeryReal::Creator::Instance()->AddCreator("TransformComponent", new VeryReal::CreatorTransformComponent());
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("a", 0);
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("position", Vector3{ 0, 0, 20 });
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("rotation", Vector3{ 0, 0, 0 });
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("scale", Vector3{ 1, 1, 1 });

        VeryReal::Creator::Instance()->AddCreator("MeshRenderComponent", new VeryReal::CreatorMeshRenderComponent());
        Creator::Instance()->GetCreator("MeshRenderComponent")->AddParameter("isstatic", true);
        Creator::Instance()->GetCreator("MeshRenderComponent")->AddParameter("modelname", std::string("Sinbad.mesh"));
        Creator::Instance()->GetCreator("MeshRenderComponent")->AddParameter("entityname", std::string("sinbad"));
        Creator::Instance()->GetCreator("MeshRenderComponent")->AddParameter("materialname", std::string(""));
#pragma region camara
        VeryReal::Creator::Instance()->AddCreator("CameraComponent", new VeryReal::CreatorCameraComponent());
        Creator::Instance()->GetCreator("CameraComponent")->AddParameter("name", std::string("anim"));
        Creator::Instance()->GetCreator("CameraComponent")->AddParameter("color", Vector3(0.8f, 0.3f, 1));
        Creator::Instance()->GetCreator("CameraComponent")->AddParameter("offset", Vector3{ 100, 100, 100 });
#pragma endregion
#pragma region luz
        VeryReal::Creator::Instance()->AddCreator("Light", new VeryReal::CreatorLightComponent());
        Creator::Instance()->GetCreator("Light")->AddParameter("type", 1);
        Creator::Instance()->GetCreator("Light")->AddParameter("diffusecolour", Vector3{ 1, 1, 1 });
        Creator::Instance()->GetCreator("Light")->AddParameter("shadowfardist", float(25.0));
        Creator::Instance()->GetCreator("Light")->AddParameter("shadowdist", float(25.0));
        Creator::Instance()->GetCreator("Light")->AddParameter("ineerangle", float(90.0));
        Creator::Instance()->GetCreator("Light")->AddParameter("outerangle", float(180.0));
        Creator::Instance()->GetCreator("Light")->AddParameter("nearclipdist", float(0.1));
        Creator::Instance()->GetCreator("Light")->AddParameter("shdws", true);
#pragma endregion 

#pragma region audiosource
        VeryReal::Creator::Instance()->AddCreator("AudioSourceComponent", new VeryReal::CreatorAudioSourceComponent());
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("name", std::string("sonido"));
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("path", std::string("sonido_jefe_merodeando2.mp3"));
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("groupchannel", std::string("sonido"));
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("onstart", true);
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("loop", true);
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("threed", true);
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("volume", 1000.f);
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("mindistance", 0.0f);
        Creator::Instance()->GetCreator("AudioSourceComponent")->AddParameter("maxdistance", 100000.0f);
#pragma endregion

#pragma region audiolistener
        VeryReal::Creator::Instance()->AddCreator("AudioListenerComponent", new VeryReal::CreatorAudioListenerComponent());
#pragma endregion

        VeryReal::Creator::Instance()->AddCreator("MovementComponent", new Ogreman::CreatorMovementComponent());
        VeryReal::Creator::Instance()->AddCreator("InputComponent", new Ogreman::CreatorPlayerInputComponent());
       




        VeryReal::Scene* s = SceneManager::Instance()->AddScene("Play", true);
        s = SceneManager::Instance()->GetScene("Play");
        Entity* e = s->AddEntity("Player");

        Entity* luz = s->AddEntity("Luz");
        //Entity* camara = s->AddEntity("Cam");
       // Component* cam = camara->AddComponent("Camera");
        Component* trans = luz->AddComponent("TransformComponent");
        Component* luzcom = luz->AddComponent("Light");
        Component* transform = e->AddComponent("TransformComponent");
        Component* audioSource = e->AddComponent("AudioSourceComponent");
        Component* audioListener = e->AddComponent("AudioListenerComponent");
        Component* meshrenderer = e->AddComponent("MeshRenderComponent");
        Component* mov = e->AddComponent("MovementComponent");
        Component* cam2 = e->AddComponent("CameraComponent");
       
        static_cast<CameraComponent*>(cam2)->SetTarget(e);
        Component* inpur = e->AddComponent("InputComponent");


        Entity* ogrite = s->AddEntity("VAMOS");
       Component* transfoerm= ogrite->AddComponent("TransformComponent");
        ogrite->AddComponent("MeshRenderComponent");
        static_cast<TransformComponent*>(transfoerm)->SetPosition(VeryReal::Vector3(0,0,25));
        return 0;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
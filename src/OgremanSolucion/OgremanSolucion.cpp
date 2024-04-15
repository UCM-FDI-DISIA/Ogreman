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
#include "ScriptManager.h"
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
#include "../Components/CreatorNodeComponent.h"
#include "MeshRenderComponent.h"
#include "../Components/CreatorGridComponent.h"
#include "../Components/CreatorOgremanControllerComponent.h"
#include "CreatorColliderComponent.h"
#include "../Components/NodeComponent.h"
#include "CreatorRigidBodyComponent.h"
#include "CreatorAnimatorComponent.h"
#include "AnimatorComponent.h"
#include "../Components/CreatorGridComponent.h"
#include "PhysicsManager.h"
#include "../Components/PlayButtonComponent.h"
#include "../Components/ExitButtonComponent.h"
#include "../Components/CreatorExitButtonComponent.h"
#include "../Components/CreatorPlayButtonComponent.h"
using namespace VeryReal;

extern "C"  //Para que al exportar la función de las DLLs los nombres no se contaminen (name mangling), esto es usado por el compilador para permitir la sobrecarga de funciones
{
    // Declaración de la función que deseas exportar

    __declspec(dllexport) bool start() {
        VeryReal::Creator::Instance()->AddCreator("PlayButtonComponent", new Ogreman::CreatorPlayButtonComponent());
        VeryReal::Creator::Instance()->AddCreator("ExitButtonComponent", new Ogreman::CreatorExitButtonComponent());
        VeryReal::Creator::Instance()->AddCreator("CellComponent", new Ogreman::CreatorCellComponent());
        VeryReal::Creator::Instance()->AddCreator("GridComponent", new Ogreman::CreatorGridComponent());
        VeryReal::Creator::Instance()->AddCreator("MovementComponent", new Ogreman::CreatorMovementComponent());
        VeryReal::Creator::Instance()->AddCreator("NodeComponent", new Ogreman::CreatorNodeComponent());
        VeryReal::Creator::Instance()->AddCreator("NoteComponent", new Ogreman::CreatorNoteComponent());
        VeryReal::Creator::Instance()->AddCreator("PickUpComponent", new Ogreman::CreatorPickUpComponent());
        VeryReal::Creator::Instance()->AddCreator("PlayerInputComponent", new Ogreman::CreatorPlayerInputComponent());
        VeryReal::Creator::Instance()->AddCreator("PlayerInteractionComponent", new Ogreman::CreatorPlayerInteractionComponent());
        VeryReal::Creator::Instance()->AddCreator("FlashlightComponent", new Ogreman::CreatorFlashlightComponent());
        return true;
    }

    __declspec(dllexport) int main() {
        VeryReal::RenderManager::Instance()->InitManager("app");
        VeryReal::PhysicsManager::Instance()->Initialize();
        VeryReal::Creator::Instance()->AddCreator("TransformComponent", new VeryReal::CreatorTransformComponent());
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("a", 0);
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("position", Vector3{ 0, 0,20 });
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("rotation", Vector3{ 0, 0, 0 });
        Creator::Instance()->GetCreator("TransformComponent")->AddParameter("scale", Vector3{ 1, 1, 1 });

        VeryReal::Creator::Instance()->AddCreator("MeshRenderComponent", new VeryReal::CreatorMeshRenderComponent());
        Creator::Instance()->GetCreator("MeshRenderComponent")->AddParameter("isstatic", false);
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
        VeryReal::Creator::Instance()->AddCreator("PlayerInputComponent", new Ogreman::CreatorPlayerInputComponent());
        VeryReal::Creator::Instance()->AddCreator("FlashlightComponent", new Ogreman::CreatorFlashlightComponent());
        VeryReal::Creator::Instance()->AddCreator("OgremanMovementComponent", new Ogreman::CreatorOgremanControllerComponent());
        VeryReal::Creator::Instance()->AddCreator("NodeComponent", new Ogreman::CreatorNodeComponent());
        VeryReal::Creator::Instance()->AddCreator("ColliderComponent", new VeryReal::CreatorColliderComponent());
        VeryReal::Creator::Instance()->AddCreator("RigidBodyComponent", new VeryReal::CreatorRigidBodyComponent());
        //int shapeType, float mass, float friction, float restitution, int movementType, bool trigger
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("shapeType", 1);
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("mass", float(1));
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("friction", float(0));
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("restitution", float(0));
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("movementType", int(0));
        Creator::Instance()->GetCreator("RigidBodyComponent")->AddParameter("trigger", true);

        //bool ispatrol,float cost, float hcost, int iswalkable,int i
        Creator::Instance()->GetCreator("NodeComponent")->AddParameter("id", int(1));
        Creator::Instance()->GetCreator("NodeComponent")->AddParameter("ispatrol", true);
        Creator::Instance()->GetCreator("NodeComponent")->AddParameter("iswalkable", true);
        Creator::Instance()->GetCreator("NodeComponent")->AddParameter("hcost", float(10));
        Creator::Instance()->GetCreator("NodeComponent")->AddParameter("cost", 1000.f);

        VeryReal::Creator::Instance()->AddCreator("AnimatorComponent", new VeryReal::CreatorAnimatorComponent());
        Creator::Instance()->GetCreator("AnimatorComponent")->AddParameter("name", "skeleton.mesh");
       
        VeryReal::Creator::Instance()->AddCreator("GridComponent", new Ogreman::CreatorGridComponent());



        VeryReal::Scene* s = SceneManager::Instance()->AddScene("Play", true);
        s = SceneManager::Instance()->GetScene("Play");

        /*ScriptManager::Instance()->Init("HouseScene");
        ScriptManager::Instance()->ReadScene("HouseScene");*/

        Entity* e = s->AddEntity("Player");

       // Entity* luz = s->AddEntity("Luz");
        //Entity* camara = s->AddEntity("Cam");
       // Component* cam = camara->AddComponent("Camera");
       /* Component* trans = luz->AddComponent("TransformComponent");
        Component* luzcom = luz->AddComponent("Light");*/
        Component* transform = e->AddComponent("TransformComponent");
        Component* audioSource = e->AddComponent("AudioSourceComponent");
        Component* audioListener = e->AddComponent("AudioListenerComponent");
        //Component* meshrenderer = e->AddComponent("MeshRenderComponent");
        Component* mov = e->AddComponent("MovementComponent");
        Component* cam2 = e->AddComponent("CameraComponent");
        Component* foco = e->AddComponent("Light");

        static_cast<CameraComponent*>(cam2)->SetTarget(e);
        Component* inpur = e->AddComponent("PlayerInputComponent");

        Component* linterna = e->AddComponent("FlashlightComponent");

        /*Entity* ogrite = s->AddEntity("VAMOS");
        Component* transfoerm= ogrite->AddComponent("TransformComponent");
        ogrite->AddComponent("MeshRenderComponent");
        static_cast<TransformComponent*>(transfoerm)->SetPosition(VeryReal::Vector3(0,0,205));*/

      
        #pragma region NODES

        Entity* n1 = s->AddEntity("nodo1");
        Component* trans_n = n1->AddComponent("TransformComponent");
        static_cast<TransformComponent*>(trans_n)->SetPosition(VeryReal::Vector3(-10, 0, -25));
        static_cast<TransformComponent*>(trans_n)->Rotate(VeryReal::Vector3(0, 10, 180));
        Component* meshr_n1 = n1->AddComponent("MeshRenderComponent");
        static_cast<MeshRenderComponent*>(meshr_n1)->changeMaterial("Ogre/ring");
        Component* node_n1 = n1->AddComponent("NodeComponent");
        Component* node_collider = n1->AddComponent("ColliderComponent");
        Component* rbn1 = n1->AddComponent("RigidBodyComponent");

        Entity* n2 = s->AddEntity("nodo2");
        Component* trans_n2 = n2->AddComponent("TransformComponent");
        static_cast<TransformComponent*>(trans_n2)->SetPosition(VeryReal::Vector3(0, 10, -25));
        static_cast<TransformComponent*>(trans_n2)->Rotate(VeryReal::Vector3(0, 10, 180));
        Component* meshr_n2 = n2->AddComponent("MeshRenderComponent");
        static_cast<MeshRenderComponent*>(meshr_n2)->changeMaterial("Ogre/ring");
        Component* node_n2 = n2->AddComponent("NodeComponent");
        static_cast<Ogreman::NodeComponent*>(node_n2)->setID(1);
        Component* node_collider2 = n2->AddComponent("ColliderComponent");
        Component* rbn2 = n2->AddComponent("RigidBodyComponent");

        #pragma endregion

        Entity* ogroman = s->AddEntity("ogreman");
        Component* trans_ogreman = ogroman->AddComponent("TransformComponent");
        static_cast<TransformComponent*>(trans_ogreman)->SetPosition(VeryReal::Vector3(20, 0, -25));
        Component* meshr_ogreman = ogroman->AddComponent("MeshRenderComponent");
        Component* rb4 = ogroman->AddComponent("AnimatorComponent");
        Component* ogro_collider = ogroman->AddComponent("ColliderComponent");


        //std::cout << "Hola buenas tardes";
        //VeryReal::PhysicsManager::Instance()->Initialize();
        //VeryReal::Scene* s = SceneManager::Instance()->AddScene("Play", true);
        //VeryReal::Creator::Instance()->AddCreator("PickUpComponent", new Ogreman::CreatorPickUpComponent());
        ////VeryReal::PhysicsManager::Instance().de
        //Entity* ejemplo = s->AddEntity("Player");
        //Component* tr_ejemplo = ejemplo->AddComponent("TransformComponent");
        ////Component* pickup_comp = ejemplo->AddComponent("PickUpComponent");

        Component* rbn3 = ogroman->AddComponent("RigidBodyComponent");
        Component* ogro_movement = ogroman->AddComponent("OgremanMovementComponent");
        Entity* grid = s->AddEntity("grid");
       // Component* grid_c = grid->AddComponent("GridComponent");
    

       std::cout << s->GetEntities().size() << "\n";
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
// OgremanSolucion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>

#include "Creator.h"
#include "Scene.h"
#include "ScriptManager.h"


//creators por orden:
#include "../Components/CreatorCellComponent.h"
#include "../Components/CreatorExitButtonComponent.h"
#include "../Components/CreatorFlashlightComponent.h"
#include "../Components/CreatorGridComponent.h"
#include "../Components/CreatorMenuButtonComponent.h"
#include "../Components/CreatorMerodeoComponent.h"
#include "../Components/CreatorMovementComponent.h"
#include "../Components/CreatorNodeComponent.h"
#include "../Components/CreatorNoteComponent.h"
#include "../Components/CreatorOgremanAttackComponent.h"
#include "../Components/CreatorOgremanControllerComponent.h"
#include "../Components/CreatorOgremanHearingComponent.h"
#include "../Components/CreatorPickUpComponent.h"
#include "../Components/CreatorPlayButtonComponent.h"
#include "../Components/CreatorPlayerInputComponent.h"
#include "../Components/CreatorPlayerInteractionComponent.h"
#include "../Components/CreatorRangosVisionComponent.h"

#include "../Components/GameManager.h"

using namespace VeryReal;

extern "C"  //Para que al exportar la función de las DLLs los nombres no se contaminen (name mangling), esto es usado por el compilador para permitir la sobrecarga de funciones
{
    // Declaración de la función que deseas exportar

    __declspec(dllexport) bool start() {
        //CREACION DE TODOS LOS COMPONENETES DEL JUEGO
        Ogreman::GameManager::Init();
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
        VeryReal::Creator::Instance()->AddCreator("MerodeoMovementComponent", new Ogreman::CreatorMerodeoComponent());
        VeryReal::Creator::Instance()->AddCreator("OgremanMovementComponent", new Ogreman::CreatorOgremanControllerComponent());
        VeryReal::Creator::Instance()->AddCreator("RangosVisionComponent", new Ogreman::CreatorRangosVisionComponent());

        ScriptManager::Instance()->ReadScene("HouseScene",true);
        ScriptManager::Instance()->ReadPrefabs();

        //ScriptManager::Instance()->ExposeFunctionsVoidToLua("HolaLua", Ogreman::GameManager::Instance()->HolaLua);
        //ScriptManager::Instance()->ReadFunction("HolaLuaLua", 0);
        ScriptManager::Instance()->ExposeFunctionsVoidIntToLua("GenerateTree", Ogreman::GameManager::Instance()->GenerateTree);
        ScriptManager::Instance()->ReadFunction("GenerateTreeLua", 10);
      
        return true;
    }

    __declspec(dllexport) int main() {
    }
    __declspec(dllexport) void loop()
    {
      /*  std::cout << "Pepa" << std::endl;*/
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
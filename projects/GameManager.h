#pragma once
#ifndef GAMEMANAGER_OGREMAN
#define GAMEMANAGER_OGREMAN
#include "Singleton.h"
#include "SceneManager.h"


//comentario aclaratorio: contamos con un game manager que llama al SceneManager que tiene una lista de Escenas
namespace Ogreman {
	class GameManager:public VeryReal::Singleton<GameManager>
	{
	private:
		VeryReal::SceneManager* scene_manager;
		
	public:
		
		virtual ~GameManager();
		void Start();
		void Update(const double& dt);
		void Win();
		void Loose();
		void Menu();
		void Play();
		void Pause();

	};
}



#endif // GAMEMANAGER_OGREMAN


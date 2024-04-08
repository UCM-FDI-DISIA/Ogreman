#pragma once
#ifndef GAMEMANAGER_OGREMAN
#define GAMEMANAGER_OGREMAN
#include "Singleton.h"
#include "SceneManager.h"
#include "NodeComponent.h"

//comentario aclaratorio: contamos con un game manager que llama al SceneManager que tiene una lista de Escenas
namespace Ogreman {
	class GameManager:public VeryReal::Singleton<GameManager>
	{
	private:
		VeryReal::SceneManager* scene_manager;
		std::list<NodeComponent*> pathNodes;
		std::list<NodeComponent*> patrolNodes;
	public:
		
		virtual ~GameManager();
		void Start();
		void Update(const double& dt);
		void Win();
		void Loose();
		void Menu();
		void Play();
		void Pause();

		inline std::list<NodeComponent*> GetPathNode() {
			return pathNodes;
		}
		void RegisterPathNode(NodeComponent* node) {
			pathNodes.push_back(node);

		}
		inline std::list<NodeComponent*> GetPatrolNode() {
			return pathNodes;
		}
		void RegisterPatrolNode(NodeComponent* node) {
			pathNodes.push_back(node);

		}
	
	};
}



#endif // GAMEMANAGER_OGREMAN
